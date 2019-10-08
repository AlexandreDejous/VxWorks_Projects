#include <taskLib.h>
#include <stdio.h>
#include <kernelLib.h>
#include <semLib.h>

#define WORK_TIME 50
#define BREAK_TIME 50

long int task_run[]={100, 450, 200};
int task_stop[]={18, 25, 30};

void task(int n)
{
        long int x;

        printf("Task %i has been started\n", n);

        while (1)
        {
                printf("taskkkkk %d: running\n", n);
                x = 1000000 * task_run[n];
                while (x > 0){ 
                	x--;
                }
                printf("taskkkkkkk %d: stopped\n", n);
                taskDelay(task_stop[n]);
        }
}

/*void digger_in_hole(int n)
{
  while (1) {
    semTake(semShovels, WAIT_FOREVER);
    printf("lower digger %d: working\n", n);
    taskDelay(WORK_TIME);
    semGive(semSoilHeap);
    semGive(semShovels);
    printf("lower digger %d: resting\n", n);
    taskDelay(BREAK_TIME);
  }
}

void digger_on_ground(int n)
{
  while (1) {
    semTake(semShovels, WAIT_FOREVER);
    printf("upper digger %d: working\n", n);
    taskDelay(WORK_TIME);
    semTake(semSoilHeap);
    semGive(semShovels);
    printf("upper digger %d: resting\n", n);
    taskDelay(BREAK_TIME);
  }
}
*/



void CreateTasks(void)
{
	while(1){
		char key = getchar();
		if (key == 'e'){
			printf("EQJHQFJ");
		}
	}
        /*int id1, id2, id3;*/

        /*  kernelTimeSlice(1); */

        /*id1=taskSpawn("Task0", 210, 0, 4096, (FUNCPTR) task, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        id2=taskSpawn("Task1", 210, 0, 4096, (FUNCPTR) task, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        id3=taskSpawn("Task2", 210, 0, 4096, (FUNCPTR) task, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);*/
	
	
	/*id3=taskSpawn("Task2", 210, 0, 4096, (FUNCPTR) task, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);*/
}
