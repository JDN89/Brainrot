// data pointer dp points to the memory cell in the memory array
// instruction pointer points to the current cell to be executed

#include "interpreter.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//WARNING: Cut the crap! stop being a fucking Java dev, this is C code. Simplify this!
Interpreter interpreter;

void initInterpreter(Interpreter *interpreter, char *source) {
  // Initialize brain cells to 0
  interpreter->ip = source;
  memset(interpreter->brain, 0, ARRAY_SIZE * sizeof(int));
  interpreter->bp = &interpreter->brain[0];
}

void freeInterpreter(Interpreter *interpreter) {
  if (interpreter != NULL) {
    printf("Free the Interpreter! \n");
    if (interpreter->ip != NULL) {

      // WARNING: Do U need to free interpreter->ip?
      free(interpreter->ip);
      interpreter->ip = NULL;
    }
    // NOTE: brainpointer doens't need to be freed since it points to a static
    // array
    interpreter->bp = NULL;
  }
}

bool isAtEnd() { return *interpreter.ip == '\0'; }

void scanner() {}

void interpret(char *source) {
  // NOTE: in case I want to dynamically allocate the Interpreter
  /*Interpreter *interpreter = (Interpreter *)malloc(sizeof(Interpreter));*/
  /*if (interpreter == NULL) {*/
  /*  perror("Failed to allocate memory for Interpreter");*/
  /*  exit(EXIT_FAILURE);*/
  /*}*/
  initInterpreter(&interpreter, source);

for(;;) {


  if (isAtEnd()) {
    printf("End of file reached \n");
    break;
  }

  switch (*interpreter.ip) {
  case '>':
    printf("> -- %c \n", *interpreter.ip);
    break;
  case '<':
    printf("< -- %c \n", *interpreter.ip);
    break;
  case '+':
    printf("< -- %c \n", *interpreter.ip);
    break;
  case '-':
    printf("< -- %c \n", *interpreter.ip);
    break;
  default:
    printf("DEFAULT -- %c \n", *interpreter.ip);
    break;
  }
  interpreter.ip++;
  }
  freeInterpreter(&interpreter);
  /*free(interpreter);*/
}
