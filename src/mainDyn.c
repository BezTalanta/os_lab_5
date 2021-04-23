#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <math.h>

#include "dnLib.h"

void WriteCommand(){
	printf("Write command: \n");
	printf("	1 <A> <B> - first function with two arguments\n");
	printf("	2 <A> <B> - second function with two arguments\n");
	printf("	<exit, e> - close programm\n");
}

int main(){
	void* handle = dlopen("libdynn.so", RTLD_LAZY);
	if(!handle){
		printf("%s\n",dlerror());
		return 1;
	}
	float (*Square1) (float A, float B) = dlsym(handle, "Square1");
	float (*Square2) (float A, float B) = dlsym(handle, "Square2");

	printf("[Stat] Program started!\n");
	WriteCommand();
	char *x = malloc(sizeof(char));
	float A,B;
	while(scanf("%s",x)){
		if(!strcmp(x, "1")){
			printf("Enter A and B: ");
			scanf("%f",&A); scanf("%f",&B);
			printf("[1] Result: %f\n", (*Square1)(A, B));
		}
		else if(!strcmp(x, "2")){
			printf("Enter A and B: ");
			scanf("%f",&A); scanf("%f",&B);
			printf("[2] Result: %f\n", (*Square2)(A, B));
		}
		else if(!strcmp(x, "e")){
			break;
		}
		else{
			printf("%s is unknown command!\n", x);
			WriteCommand();
		}
	}
	dlclose(handle);
	return 0;
}