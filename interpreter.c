// data pointer dp points to the memory cell in the memory array
// instruction pointer points to the current cell to be executed

#include <stdio.h>
#include "interpreter.h"

void initVM(VM *vm) {
	printf("init VM! \n");
	if(vm !=NULL) {
		vm->someState = 5;
	}
}

void freeVM(VM *vm) {
	if (vm == NULL) {
		return ;
	}
	//free dynamically allocated memory
	else {
		printf("free the VM! \n");
		vm->someState = 0;

	}
}
