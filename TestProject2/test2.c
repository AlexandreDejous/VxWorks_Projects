#include <taskLib.h>
#include <stdio.h>
#include <kernelLib.h>
#include <semLib.h>
#include <stdlib.h>

#define WORK_TIME 50
#define BREAK_TIME 50

long int task_run[]={100, 450, 200};
int task_stop[]={18, 25, 30};

/*Standard queue implementation in C. Found at https://gist.github.com/kroggen/5fc7380d30615b2e70fcf9c7b69997b6 */

typedef struct node {
    int val;
    struct node *next;
} node_t;

void enqueue(node_t **head, int val) {
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node) return;

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;
}

int dequeue(node_t **head) {
    node_t *current, *prev = NULL;
    int retval = -1;

    if (*head == NULL) return -1;

    current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    retval = current->val;
    free(current);
    
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    return retval;
}

/*END of queue implementation */

SEM_ID semShovels;
SEM_ID semSoilHeap;
int numberDiggers = 0;


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

void digger_in_hole(int n)
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





void CreateTasks(void)
{
  semSoilHeap = semCCreate(SEM_Q_FIFO,0 );
  semShovels = semCCreate(SEM_Q_FIFO, 3);

	while(1){
		char key = getchar();
		if (key == 'E'){
			printf("EQJHQFJ");

		}
    if (key == 'i'){//lower entering
			printf("EQJHQFJ");
      if(numberDiggers <50){
        numberDiggers++;
        
      }
      
		}
    if (key == 'o'){//lower leaving
			printf("EQJHQFJ");
      if(numberDiggers > 0){
        numberDiggers--;
      }
      
		}
		if (key == 'I'){//upper entering
			printf("EQJHQFJ");
      if(numberDiggers <50){
        numberDiggers++;

      }
		}
    if (key == 'O'){//upper leaving
			printf("EQJHQFJ");
      if(numberDiggers > 0){
        numberDiggers--;
      }
		}
	}
        /*int id1, id2, id3;*/

        /*  kernelTimeSlice(1); */

        /*id1=taskSpawn("Task0", 210, 0, 4096, (FUNCPTR) task, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        id2=taskSpawn("Task1", 210, 0, 4096, (FUNCPTR) task, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        id3=taskSpawn("Task2", 210, 0, 4096, (FUNCPTR) task, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);*/
	
	
	/*id3=taskSpawn("Task2", 210, 0, 4096, (FUNCPTR) task, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);*/
}


