#include <intLib.h>
#include <iv.h>
#include <semLib.h>
#include <taskLib.h>
#include <xlnx_zynq7k.h>

#include <stdio.h>
/*#include <stdlib.h>*/
#include <math.h>


#include <time.h>


/*ping -s 64000 -i 0.2 192.168.202.208*/

/* register offsets (see TRM B.32)*/
#define ZYNQ_TIMER_CLOCK_CTRL       (0x00)
#define ZYNQ_TIMER_COUNTER_CTRL     (0x0c)
#define ZYNQ_TIMER_COUNTER_VAL      (0x18)
#define ZYNQ_TIMER_INTERVAL         (0x24)
#define ZYNQ_TIMER_INTERRUPT        (0x54)
#define ZYNQ_TIMER_INTERRUPT_EN     (0x60)
/* register bit definitions*/
#define INTERRUPT_EN_IV             (0x01)
#define CTRL_EN                 (0<<0)
#define CTRL_DIS                    (1<<0)
#define CTRL_INT                    (1<<1)
#define CLOCK_PRESCALE              (0x01 << 1)
#define CLOCK_PRESCALE_EN           (0x1)
/* register access*/
#define TTC0_TIMER2_CLOCK_CTRL      (*((volatile UINT32 *)(ZYNQ7K_TTC0_TIMER2_BASE + ZYNQ_TIMER_CLOCK_CTRL)))
#define TTC0_TIMER2_COUNTER_CTRL    (*((volatile UINT32 *)(ZYNQ7K_TTC0_TIMER2_BASE + ZYNQ_TIMER_COUNTER_CTRL)))
#define TTC0_TIMER2_COUNTER_VAL     (*((volatile UINT32 *)(ZYNQ7K_TTC0_TIMER2_BASE + ZYNQ_TIMER_COUNTER_VAL)))
#define TTC0_TIMER2_INTERVAL        (*((volatile UINT32 *)(ZYNQ7K_TTC0_TIMER2_BASE + ZYNQ_TIMER_INTERVAL)))
#define TTC0_TIMER2_INTERRUPT       (*((volatile UINT32 *)(ZYNQ7K_TTC0_TIMER2_BASE + ZYNQ_TIMER_INTERRUPT)))
#define TTC0_TIMER2_INTERRUPT_EN    (*((volatile UINT32 *)(ZYNQ7K_TTC0_TIMER2_BASE + ZYNQ_TIMER_INTERRUPT_EN)))

#define TIM_MAX 8000

unsigned t1 = 0;
unsigned t2 = 0;
unsigned arr1[300]={0};
unsigned arr2[300]={0};
int temp1;
int temp2;


SEM_ID semaphore;

void timer_isr(){
	t1 = TTC0_TIMER2_COUNTER_VAL;
	semGive(semaphore);
	temp1 = ((t1*36)/1000);
	arr1[temp1]++;
	TTC0_TIMER2_INTERRUPT;
}

void timer_service(){
	while(1){
		semTake(semaphore,WAIT_FOREVER);
		t2 = TTC0_TIMER2_COUNTER_VAL;
		temp2 = floor((t2*36)/1000);
		arr2[temp2]++;
		/*printf("%u",t2);*/
	}
}

void init(){
	TTC0_TIMER2_COUNTER_CTRL = CTRL_DIS;
	TTC0_TIMER2_CLOCK_CTRL = CLOCK_PRESCALE | CLOCK_PRESCALE_EN;
	TTC0_TIMER2_INTERVAL = TIM_MAX; /* See "Choosing the timer period" below*/
	TTC0_TIMER2_INTERRUPT_EN = INTERRUPT_EN_IV;
	TTC0_TIMER2_COUNTER_CTRL = CTRL_INT | CTRL_EN;

	/* interrupt init*/
	intConnect(INT_VEC_TTC0_2, timer_isr, 0);
	intEnable(INT_LVL_TTC0_2);

	/* uninit all*/
	/*TTC0_TIMER2_COUNTER_CTRL = CTRL_DIS;
	intDisable(INT_LVL_TTC0_2);
	intDisconnect(INT_VEC_TTC0_2, timer_isr, 0);*/
}

/* timer init (see TRM 8.5.5)*/


void monitor(){
	
	/*printf("HI\n");*/
	/*int taskAddr =*/ 
	printf("/");
	int n = 60;
	int i = 0;
	while(n>0){
		printf("%d",n);
		taskDelay(10000);
		printf("s");
		n--;
	}
	
	/*while (1){
		if (){
			
		}
	}*/
}

void main(){
	printf("program launched");
	taskSpawn("service_task", 210, 0, 4096, (FUNCPTR) timer_service, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf(".");
	taskSpawn("monitor_task", 210, 0, 4096, (FUNCPTR) monitor, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf(".");
	init();
	printf(".");
	/*int n = 60;
	int i = 0;
	while(n>0){
		sleep(1);
		printf("/");*/
		/*for (i=0;i<300;i++){
			printf("%u;",arr1[i]);
		}*/
		/*printf("/n");*/
		/*n--;
	}*/
}

