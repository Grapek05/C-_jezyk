#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* stack_new() {
    Stack* s = malloc(sizeof(Stack));
    if (!s) {
        fprintf(stderr, "Błąd alokacji stosu.\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    return s;
}

void stack_push(Stack* s, int value) {
    Node* n = malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "Błąd alokacji węzła.\n");
        exit(EXIT_FAILURE);
    }
    n->value = value;
    n->next = s->top;
    s->top = n;
}

int stack_pop(Stack* s) {
    if (!s->top) return 0;
    Node* tmp = s->top;
    int value = tmp->value;
    s->top = tmp->next;
    free(tmp);
    return value;
}

int stack_empty(Stack* s) {
    return s->top == NULL;
}

void stack_print(Stack* s) {
    Node* n = s->top;
    printf("Stos: ");
    while (n) {
        printf("%d ", n->value);
        n = n->next;
    }
    printf("\n");
}

void stack_free(Stack* s) {
    while (!stack_empty(s)) {
        stack_pop(s);
    }
    free(s);
}
