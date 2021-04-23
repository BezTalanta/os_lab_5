#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stLib.h"

void WriteCommand(){
	printf("Write command: \n");
	printf("	1 <A> <deltaX> - first function with two arguments\n");
	printf("	2 <A> <deltaX> - second function with two arguments\n");
	printf(" 	<e> - close programm\n");
}

int main(){
	printf("[Stat] Program started!\n");
	WriteCommand();
	char *x = malloc(sizeof(char));
	float A, deltaX;
	while(scanf("%s",x)){
		if(!strcmp(x, "1")){
			printf("Enter A and deltaX: ");
			scanf("%f",&A); scanf("%f",&deltaX);
			printf("[1] Result: %f\n",function1(A, deltaX));
		}
		else if(!strcmp(x, "2")){
			printf("Enter A and deltaX: ");
			scanf("%f",&A); scanf("%f",&deltaX);
			printf("[2] Result: %f\n",function2(A, deltaX));
		}
		else if(!strcmp(x, "e")){
			break;
		}
		else{
			WriteCommand();
		}
	}
	return 0;
}