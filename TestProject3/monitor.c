#include <taskLib.h>
#include <stdio.h>
#include <semLib.h>
#include <stdlib.h>

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


