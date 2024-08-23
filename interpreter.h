#ifndef INTERPRETER_H
#define INTERPRETER_H


// TODO: create VM_H file use in lib.c
// add dp array and ip array -> points to the instruction stream
// NOTE: when to use free()? I think when u use malloc
// free is to free the allocated memory
// then you set the pointer to NULL
// TODO: write test for state initialization and freeing?
// TODO: init the object in main.c and free it at the end in main.c
// read string and pass pointer to string
// NOTE: do I need to free static arrays?
// https://stackoverflow.com/questions/37131659/why-dont-static-arrays-need-to-be-freed
// maybe call file interpret <> bytecode interpreter <> compiler (assembly)
// NOTE: use asserts to test your code -> test_lib.c
//
// WARNING:My interpreter file should havae it's own vm struct
// just put all the logic in interpreter<>bytecodeVM<>compiler file and call
// from c. no lib chananigans. the brainfuck language is small anyways

#define ARRAY_SIZE 30000

typedef struct {
  // pass the whole instruction string
  char *ip;
  // lifetime brais is same as lifetime VM 
  int brain[ARRAY_SIZE];  
  int *brainPointer;
} VM;

void initVM(VM *vm, char *source);
void freeVM(VM *vm);

#endif
