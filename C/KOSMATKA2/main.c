#include <stdio.h>
#include "stack.c"

int main(void) {
    Stack* s = stack_new();
    stack_push(s, 1);
    stack_push(s, 0);
    stack_push(s, 1);
    stack_push(s, 1);
    stack_push(s, 1);
    stack_pop(s);
    stack_push(s, 0);

    stack_print(s);

    unsigned int value = 0;
    for (size_t i = 0; !stack_empty(s); i++) {
        value += stack_pop(s) << i;
    }

    printf("Wartość: %u\n", value);
    stack_free(s);
    return 0;
}
