#include <stdio.h>
#include "interpreter.h"

int main () {
	VM vm;	
	initVM(&vm);
	printf("It smells like brainrot in here! \n");
	freeVM(&vm);
}
