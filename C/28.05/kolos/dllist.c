#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

dllist* dllist_new(void) {
    dllist *d = malloc(sizeof(dllist));
    if (d) {
        d->head = NULL;
        d->tail = NULL;
    }
    return d;
}

void dllist_free(dllist *d) {
    node *current = d->head;
    while (current) {
        node *next = current->next;
        free(current);
        current = next;
    }
    free(d);
}

void dllist_append(dllist *d, float value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = d->tail;

    if (d->tail) {
        d->tail->next = new_node;
    } else {
        d->head = new_node;
    }
    d->tail = new_node;
}

void dllist_prepend(dllist *d, float value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = d->head;

    if (d->head) {
        d->head->prev = new_node;
    } else {
        d->tail = new_node;
    }
    d->head = new_node;
}

node* dllist_head(dllist *d) {
    return d->head;
}

node* dllist_tail(dllist *d) {
    return d->tail;
}

void dllist_remove(dllist *d, node *n) {
    if (!n) return;

    if (n->prev) {
        n->prev->next = n->next;
    } else {
        d->head = n->next;
    }

    if (n->next) {
        n->next->prev = n->prev;
    } else {
        d->tail = n->prev;
    }

    free(n);
}

size_t dllist_len(const dllist *d) {
     size_t count = 0;
     node *current = d->head;
     while (current) {
        count++;
        current = current->next;
     }
     return count;
}

void dllist_print(const dllist *d) {
    node *current = d->head;
    printf("[");
    while (current) {
        printf("%.2f", current->value);
        if (current->next) {
            printf(", ");
        }
        current = current->next;
    }
    printf("%.2f");
}

