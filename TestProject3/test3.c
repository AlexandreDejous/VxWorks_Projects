/*README

Implemented:
-diggers tasks spawing and deletion (upper and lower)
-press c to get a general view of the workplace (how much diggers are working and worked today)
-info message (ex. upper digger 6 exiting... ; lower digger 3 entering...)
I used a queue to implement the FIFO rule about diggers (first arrived to the workplace, first to leave)
Upper diggers are waiting a finite amount of time to check if there is soil to remove
*/




#include <taskLib.h>
#include <stdio.h>
#include <semLib.h>
#include <stdlib.h>

#define WORK_TIME 50
#define BREAK_TIME 50


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

node_t *LDiggersID = NULL;/*stqck containing the ID (number, order of arrival) of each digger */
node_t *UDiggersID = NULL;
int ret;

/*END of queue instantiation */

SEM_ID semShovels;
SEM_ID semSoilHeap;
int numberDiggers = 0;
int numberLDiggers = 0;
int numberUDiggers = 0;
int numberLDiggersCumul = 0;/*cumulated number of diggers since the beggining, useful for giving them a unique name*/
int numberUDiggersCumul = 0;




void digger_in_hole(int n)
{
	printf("lower digger %d: arriving\n", n);
  while (1) {
    
    taskSafe();
    semTake(semShovels, WAIT_FOREVER);/* hope it will return the shovel if the task gets terminated en route */
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
  printf("lower digger %d: arriving\n", n);
  while (1) {
    
    
    
    semTake(semSoilHeap, WAIT_FOREVER);/*if it is work time but still no soil after a moment, rest*/
    taskSafe();
    semTake(semShovels, WAIT_FOREVER);
    taskDelay(WORK_TIME);
    
    printf("upper digger %d: working\n", n);
    semGive(semShovels);
    taskUnsafe();
    printf("upper digger %d: resting\n", n);
    taskDelay(BREAK_TIME);
  }
}


void createLowerDigger(){
	  numberLDiggers++; 
	  numberLDiggersCumul++;
	  char diggerName[11];
	  snprintf(diggerName, 11, "tWorkerL%d", numberLDiggersCumul-1);
	  printf("lower digger %d: arriving\n", numberLDiggersCumul-1);
	  int taskAddr = taskSpawn(diggerName, 210, 0, 4096, (FUNCPTR) digger_in_hole, numberLDiggersCumul-1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	  enqueue(&LDiggers, taskAddr);
	  enqueue(&LDiggersID, numberLDiggersCumul-1);	  
}

void createUpperDigger(){
	numberUDiggers++;
	numberUDiggersCumul++;
	char diggerName[11];
	snprintf(diggerName, 11, "tWorkerU%d", numberUDiggersCumul-1);
	printf("upper digger %d: arriving\n", numberUDiggersCumul-1);
	int taskAddr = taskSpawn(diggerName, 210, 0, 4096, (FUNCPTR) digger_on_ground, numberUDiggersCumul-1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	enqueue(&UDiggers, taskAddr);
	enqueue(&UDiggersID, numberUDiggersCumul-1);
}


void main(void)
{
  semSoilHeap = semCCreate(SEM_Q_FIFO,0 );
  semShovels = semCCreate(SEM_Q_FIFO, 3);
  int taskAddr;
  int i = 0;
  int ret = 0;
  
  
  /*initial miners*/
  createLowerDigger();
  createUpperDigger();
  
  
  
	while(1){
		char key = getchar();
		if (key == 'E'){
			
      if(numberUDiggers + numberLDiggers > 0){
        printf("Everyone goes home!\n");

        if (numberUDiggers > 0){
          for (i=0; i<=numberUDiggers-1; i++){
          
          ret = dequeue(&UDiggersID);
          printf("upper digger %d: leaving\n", ret);
          taskAddr = dequeue(&UDiggers);
          taskDelete(taskAddr);

          }
          numberUDiggers = 0;
        }
        if (numberLDiggers > 0){
          for (i=0; i<=numberLDiggers-1; i++){
          ret = dequeue(&LDiggersID);
          printf("lower digger %d: leaving\n", ret);
          taskAddr = dequeue(&LDiggers);
          taskDelete(taskAddr);

          }
          numberLDiggers = 0;
        }
      }
      else
      {
        printf("Number of diggers already 0\n");
      }


		}
    if (key == 'i'){/*lower entering */
			
      if(numberUDiggers + numberLDiggers <50){
        createLowerDigger();
      }
      
		}
    if (key == 'o'){/*lower leaving */

      if(numberLDiggers > 0){
        numberLDiggers--;
        ret = dequeue(&LDiggersID);
        printf("lower digger %d: leaving\n", ret);
        taskAddr = dequeue(&LDiggers);
        taskDelete(taskAddr);
      }
      else
      {
        printf("Number of lower diggers already 0\n");
      }
      
      
		}
		if (key == 'I'){/* upper entering*/

      if(numberUDiggers + numberLDiggers <50){
    	  createUpperDigger();
        

      }
		}
    if (key == 'O'){/*upper leaving */
      if(numberUDiggers > 0){
        numberUDiggers--;
        ret = dequeue(&UDiggersID);
        printf("upper digger %d: leaving\n", ret);
        taskAddr = dequeue(&UDiggers);
        taskDelete(taskAddr);
      }
      else
      {
        printf("Number of upper diggers already 0\n");
      }
		}
		if (key == 'c'){/* workplace status*/
			printf("%d lower diggers\n", numberLDiggers);
			printf("%d upper diggers\n", numberUDiggers);
			printf("%d lower diggers worked today\n", numberLDiggersCumul);
			printf("%d upper diggers worked today\n", numberUDiggersCumul);
			print_list(LDiggers);
			printf("\n-----\n");
			/*print_list(UDiggers);*/
		}
	}

}

