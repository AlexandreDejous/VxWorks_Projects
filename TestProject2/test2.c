#include <taskLib.h>
#include <stdio.h>
#include <kernelLib.h>
#include <semLib.h>
#include <stdlib.h>

#define WORK_TIME 50
#define BREAK_TIME 50

/* long int task_run[]={100, 450, 200};
int task_stop[]={18, 25, 30};*/

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

void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

/*END of queue implementation */

/*Queue instantiation */

node_t *LDiggers = NULL;
node_t *UDiggers = NULL;
int ret;

/*END of queue instantiation */

SEM_ID semShovels;
SEM_ID semSoilHeap;
int numberDiggers = 0;
int numberLDiggers = 0;
int numberUDiggers = 0;
int numberLDiggersCumul = 0;/*cumulated number of diggers since the beggining, useful for giving them a unique name*/
int numberUDiggersCumul = 0;


/* void task(int n)
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
}*/

void digger_in_hole(int n)
{
  while (1) {
    semTake(semShovels, WAIT_FOREVER);/* hope it will return the shovel if the task gets terminated en route */
    taskSafe();
    printf("lower digger %d: working\n", n);
    taskDelay(WORK_TIME);
    semGive(semSoilHeap);
    semGive(semShovels);
    taskUnsafe();
    printf("lower digger %d: resting\n", n);
    taskDelay(BREAK_TIME);
  }
}

void digger_on_ground(int n)
{
  while (1) {
    semTake(semShovels, WAIT_FOREVER);
    taskSafe();
    printf("upper digger %d: working\n", n);
    
    taskDelay(WORK_TIME);
    semTake(semSoilHeap, WAIT_FOREVER);
    semGive(semShovels);
    taskUnsafe();
    printf("upper digger %d: resting\n", n);
    taskDelay(BREAK_TIME);
  }
}





void CreateTasks(void)
{
  semSoilHeap = semCCreate(SEM_Q_FIFO,0 );
  semShovels = semCCreate(SEM_Q_FIFO, 3);
  int taskAddr;
  int i = 0;
	while(1){
		char key = getchar();
		if (key == 'E'){
			
      if(numberUDiggers + numberLDiggers > 0){
        printf("Everyone goes home!");

        if (numberUDiggers > 0){
          for (i=0; i<=numberUDiggers; i++){
          numberUDiggers--;
          printf("upper digger %d exiting", numberUDiggersCumul-1);
          taskAddr = dequeue(&UDiggers);
          taskDelete(taskAddr);

          }
        }
        if (numberLDiggers > 0){
          for (i=0; i<=numberLDiggers; i++){
          numberLDiggers--;
          printf("lower digger %d exiting", numberLDiggersCumul-1);
          taskAddr = dequeue(&LDiggers);
          taskDelete(taskAddr);

          }
        }
      }
      else
      {
        printf("Number of diggers already 0");
      }


		}
    if (key == 'i'){/*lower entering */
			
      if(numberUDiggers + numberLDiggers <50){
        numberLDiggers++; 
        numberLDiggersCumul++;
        char diggerName[11];
        snprintf(diggerName, 11, "tWorkerL%d", numberLDiggersCumul-1);
        printf("lower digger %d entering", numberLDiggersCumul-1);
        taskAddr = taskSpawn(diggerName, 210, 0, 4096, (FUNCPTR) digger_in_hole, numberLDiggersCumul-1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        enqueue(&LDiggers, taskAddr);
      }
      
		}
    if (key == 'o'){/*lower leaving */
			printf("EQJHQFJ");
      if(numberLDiggers > 0){
        numberLDiggers--;
        printf("lower digger %d exiting", numberLDiggersCumul-1);
        taskAddr = dequeue(&LDiggers);
        taskDelete(taskAddr);
      }
      else
      {
        printf("Number of lower diggers already 0");
      }
      
      
		}
		if (key == 'I'){/* upper entering*/
			/* printf("EQJHQFJ");*/
      if(numberUDiggers + numberLDiggers <50){
        numberUDiggers++;
        numberUDiggersCumul++;
        char diggerName[11];
        snprintf(diggerName, 11, "tWorkerU%d", numberUDiggersCumul-1);
        printf("upper digger %d entering", numberUDiggersCumul-1);
        taskAddr = taskSpawn(diggerName, 210, 0, 4096, (FUNCPTR) digger_on_ground, numberUDiggersCumul-1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        enqueue(&UDiggers, taskAddr);

      }
		}
    if (key == 'O'){/*upper leaving */
			/* printf("EQJHQFJ");*/
      if(numberUDiggers > 0){
        numberUDiggers--;
        printf("upper digger %d exiting", numberUDiggersCumul-1);
        taskAddr = dequeue(&UDiggers);
        taskDelete(taskAddr);
      }
      else
      {
        printf("Number of upper diggers already 0");
      }
		}
		if (key == 'c'){/* workplace status*/
			printf("%d lower diggers\n", numberLDiggers);
			printf("%d upper diggers\n", numberUDiggers);
			printf("%d lower diggers worked today\n", numberLDiggersCumul);
			printf("%d upper diggers worked today\n", numberUDiggersCumul);
			print_list(LDiggers);
      printf("\n-----\n");
      print_list(UDiggers);
		}
	}
        /*int id1, id2, id3;*/

        /*  kernelTimeSlice(1); */

        /*id1=taskSpawn("Task0", 210, 0, 4096, (FUNCPTR) task, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        id2=taskSpawn("Task1", 210, 0, 4096, (FUNCPTR) task, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        id3=taskSpawn("Task2", 210, 0, 4096, (FUNCPTR) task, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);*/
	
	
	/*id3=taskSpawn("Task2", 210, 0, 4096, (FUNCPTR) task, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);*/
}


