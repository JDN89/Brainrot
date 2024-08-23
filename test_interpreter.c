#include "interpreter.h"
#include <stdio.h>
#include <assert.h>

void test_InitVM_ShouldInitializeVMCorrectly(void) {
    VM testVM;
    initVM(&testVM);

    if (testVM.someState != 2) {
        fprintf(stderr, "test_InitVM_ShouldInitializeVMCorrectly FAILED: expected someState to be 2, but got %d\n", testVM.someState);
        assert(0); // Force a failure
    } else {
        printf("test_InitVM_ShouldInitializeVMCorrectly PASSED\n");
    }
}

void test_freeVM_ShouldNotCrash(void) {
    VM testVM;
    initVM(&testVM);
    freeVM(&testVM);

    if (testVM.someState != 0) {
        fprintf(stderr, "test_freeVM_ShouldNotCrash FAILED: expected someState to be 0 after freeVM, but got %d\n", testVM.someState);
        assert(0); // Force a failure
    } else {
        printf("test_freeVM_ShouldNotCrash PASSED\n");
    }
}

int main(void) {
    test_InitVM_ShouldInitializeVMCorrectly();
    test_freeVM_ShouldNotCrash();
    printf("All tests passed!\n");
    return 0;
}
