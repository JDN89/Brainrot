// data pointer dp points to the memory cell in the memory array
// instruction pointer points to the current cell to be executed

#include "interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initVM(VM *vm, char *source) {
  printf("init VM! \n");
  if (vm != NULL) {
    // NOTE: Initialize brainpointer
    if (source != NULL) {
      // WARNING: check how we copied a string in CLOX. This doesn't ring a bell
      // duplicate the source string
      vm->ip = strdup(source);
      if (vm->ip == NULL) {
        perror("Failed to initiazlize the IP");
        exit(EXIT_FAILURE);
      }
    } else {
      vm->ip = NULL;
    }

    // initialize brain
    memset(vm->brain, 0, ARRAY_SIZE * sizeof(int));
    vm->brainPointer = &vm->brain[0];
  }
}

void freeVM(VM *vm) {
  if (vm != NULL) {
    printf("Free the VM! \n");
    if (vm->ip != NULL) {

      free(vm->ip);
      vm->ip = NULL;
    }
    // NOTE: brainpointer doens't need to be freed since it points to a static
    // array
    vm->brainPointer = NULL;
  }
}
