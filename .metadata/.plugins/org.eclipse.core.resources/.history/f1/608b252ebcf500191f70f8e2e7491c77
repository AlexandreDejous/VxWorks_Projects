#include <taskLib.h>
#include <stdio.h>
#include <semLib.h>
#include <stdlib.h>

/* Companies data types definition */

struct company {
    char name[20];
    int work_done;
};

struct company_registry {
    struct company companies[50];
    int occupied[50]; /* 0 if the correponding index is not occupied by a company, 1 else*/
};

struct company_registry *ptr;

/* END of companies data types definition */

void printInConsole(){
	printf("lets print");
}

void main(int argc, char *argv[]){
	
	printf("monitor started");
	printInConsole();
	while(1){
		char key = getchar();
		if (key == 'E'){
			printf("E detected");
			
			return;
		}
				
	}
}


