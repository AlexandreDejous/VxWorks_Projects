#include "config.h"
#include <semLib.h>
#include <stdlib.h>
#include <stdio.h>

SEM_ID mutex;



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

void high(){//TODO : TWEAK THIS
	
	struct timespec tstart, tend, result;
	
	while (1) {
	  
		
		  clock_gettime(CLOCK_MONOTONIC, &tstart);
		  semTake(mutex, WAIT_FOREVER);
		  clock_gettime(CLOCK_MONOTONIC, &tend);
		  semGive(mutex);
		  timespec_subtract(&result, &tend, &tstart);
		  taskDelay(HIGH_PRIORITY_DELAY); /* let other tasks run */
	}
}

void med(){
	
}
void low(){
	
}


void main(int argc, char *argv[]){
	
	
	mutex = semMCreate(SEM_Q_PRIORITY);
	//mutex = semMCreate(SEM_Q_PRIORITY | SEM_INVERSION_SAFE );
	

	//semTake(mutex, WAIT_FOREVER);
	
	
	//0 = highest piority
	id1=taskSpawn("tHPrio", 210, 0, 4096, (FUNCPTR) high, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	id2=taskSpawn("tMPrio", 210, 0, 4096, (FUNCPTR) med, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	id3=taskSpawn("tLPrio", 210, 0, 4096, (FUNCPTR) low, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	
}
