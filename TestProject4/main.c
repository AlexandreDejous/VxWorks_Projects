// to use the board : gtkterm -p ttyUSB0 -s 115200



#include "config.h"
#include <semLib.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <taskLib.h>
#include <cpuset.h>
#include <sched.h>

SEM_ID mutex;

//int tHdosmth = 1;
//int tMdosmth = 1;
//int tLdosmth = 2;

int numMeasurements;
int endPrgm = 0; 

int timespec_subtract (struct timespec *result,
           struct timespec *x,
           struct timespec *y)
{
  /* Perform the carry for the later subtraction by updating Y. */
  if (x->tv_nsec < y->tv_nsec) {
    int num_sec = (y->tv_nsec - x->tv_nsec) / 1000000000 + 1;
    y->tv_nsec -= 1000000000 * num_sec;
    y->tv_sec += num_sec;
  }
  if (x->tv_nsec - y->tv_nsec > 1000000000) {
    int num_sec = (x->tv_nsec - y->tv_nsec) / 1000000000;
    y->tv_nsec += 1000000000 * num_sec;
    y->tv_sec -= num_sec;
  }

  /* Compute the time remaining to wait.
     `tv_nsec' is certainly positive. */
  result->tv_sec = x->tv_sec - y->tv_sec;
  result->tv_nsec = x->tv_nsec - y->tv_nsec;

  /* Return 1 if result is negative. */
  return x->tv_sec < y->tv_sec;
}

void do_something(int x)
{
    long int len = x * 10000000;
    while (len > 0) len--;
}


void high(){//TODO : TWEAK THIS
	
	
	struct timespec tstart, tend, result, maxResult;
	int countMeasurements = 0;
	maxResult.tv_nsec = 0;
	
	while (1) {		
		//printf("high\n");
		clock_gettime(CLOCK_MONOTONIC, &tstart);
		semTake(mutex, WAIT_FOREVER);
		clock_gettime(CLOCK_MONOTONIC, &tend);
		semGive(mutex);
		timespec_subtract(&result, &tend, &tstart);
		
		//print the max
		if (maxResult.tv_nsec<result.tv_nsec){
			maxResult.tv_nsec = result.tv_nsec; 
			if(endPrgm == 0){
				printf("%ld\n",result.tv_nsec/1000000);//maxResult here
			}
		}
		
		/*
		if(endPrgm == 0){
			printf("%ld\n",result.tv_nsec/1000000);//maxResult here
		}
		*/
		
		
		
		//check if program should emd
		countMeasurements++;
		if (countMeasurements >= numMeasurements){
			endPrgm = 1;
		}
		
		
		taskDelay(HIGH_PRIORITY_DELAY); /* let other tasks run */
	}
}

void med(){
	while (1) {
		//printf("mid\n");
		do_something(MID_PRIORITY_WORK);
		taskDelay(MID_PRIORITY_DELAY); /* this delay can be even zero - do you know why? */
	}
}
void low(){
	while (1) {
		//printf("low\n");
		semTake(mutex, WAIT_FOREVER);
		do_something(LOW_PRIORITY_WORK);
		semGive(mutex);
		taskDelay(LOW_PRIORITY_DELAY); /* this delay can be even zero - do you know why? */
	}
}


void main(int argc, char *argv[]){
	
	int id1, id2, id3;
	
	//if (argv[1])
	
	
	int arg1 = atoi(argv[1]);
	int arg2 = atoi(argv[2]);
	
	numMeasurements = arg2;
	
	if (arg1 == 1){//PH off
		mutex = semMCreate(SEM_Q_FIFO);
	}else if(arg1 == 2){//PH on
		mutex = semMCreate(SEM_Q_PRIORITY | SEM_INVERSION_SAFE );
	}else{//unrecognized
		return;
	}
	
	
	//0 = highest piority
	printf("Measurement started\n");
	
	
	
	
	
	//BOARD PART : please uncomment this for the board, and comment the simulator part
	//-----------------------------------------------
	//create the tasks (versus spawning em if we re tryin to simulate)
	id3=taskCreate("tLPrio", LOW_PRIORITY, 0, 4096, (FUNCPTR) low, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	id2=taskCreate("tMPrio", MID_PRIORITY, 0, 4096, (FUNCPTR) med, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	id1=taskCreate("tHPrio", HIGH_PRIORITY, 0, 4096, (FUNCPTR) high, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	
	//affinity def
	cpuset_t affinity;
	// Clear the affinity CPU set and set index for CPU 1 
	CPUSET_ZERO (affinity);
	CPUSET_SET  (affinity, 0);
	
	//affinity set
	taskCpuAffinitySet (id1, affinity);
	taskCpuAffinitySet (id2, affinity);
	taskCpuAffinitySet (id3, affinity);
	
	//activate the tasks
	taskActivate (id1);
	taskActivate (id2);
	taskActivate (id3);
	//-------------------------------------------------
	
	
	
	/*
	//SIMULATOR PART : please uncomment this for the simulator, and comment the board part
	//-----------------------------------------------
	id3=taskSpawn("tLPrio", LOW_PRIORITY, 0, 4096, (FUNCPTR) low, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	id2=taskSpawn("tMPrio", MID_PRIORITY, 0, 4096, (FUNCPTR) med, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	id1=taskSpawn("tHPrio", HIGH_PRIORITY, 0, 4096, (FUNCPTR) high, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	//--------------------------------------------------
	*/
	
	
	
	//while loop so that the program does not end because of the main
	while(1){
		if (endPrgm == 1){
			printf("Measurement finished\n");
			taskDelete(id1);
			taskDelete(id2);
			taskDelete(id3);
			return;
		}
	}
	
	
	
	
	
}

