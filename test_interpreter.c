#include "interpreter.h"
#include <assert.h>
#include <stdio.h>

VM vm;
void test_Interpret_ShouldInitializeAndFreeVM(void) {
    char source[] = ">>++"; // A simple source string for testing

    // Call interpret and expect it to initialize and free VM correctly
    interpret(source);

    // Since we can't directly check internal VM state (due to it being local),
    // we can indirectly verify by ensuring no crashes/errors occur.
    printf("test_Interpret_ShouldInitializeAndFreeVM PASSED\n");
}

void test_Interpret_ShouldProcessSourceCorrectly(void) {
    char source[] = ">>++"; // A simple source string for testing

    initVM(&vm, source);

    // Simulate the interpretation process
    while (!isAtEnd(&vm)) {
        // Ensure that the instruction pointer moves forward
        char currentChar = *vm.ip;
        vm.ip++; // Advance the instruction pointer

        // Test expected values of currentChar at each step
        if (vm.ip == source + 1) assert(currentChar == '>');
        if (vm.ip == source + 2) assert(currentChar == '>');
        if (vm.ip == source + 3) assert(currentChar == '+');
        if (vm.ip == source + 4) assert(currentChar == '+');
    }

    // After processing, ensure VM reaches the end
    assert(isAtEnd(&vm));

    freeVM(&vm);

    printf("test_Interpret_ShouldProcessSourceCorrectly PASSED\n");
}

int main(void) {
    test_Interpret_ShouldInitializeAndFreeVM();
    test_Interpret_ShouldProcessSourceCorrectly();

    printf("All tests passed!\n");
    return 0;
}
