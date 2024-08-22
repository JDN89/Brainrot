// data pointer dp points to the memory cell in the memory array
// instruction pointer points to the current cell to be executed

#include <stdio.h>
#include "lib.h"

void initVM(VM *vm) {
	if(vm !=NULL) {
		vm->someState = 0;
	}
}

void freeVM(VM *vm) {
	if (vm == NULL) {
		return ;
	}
	else {

	}
}
