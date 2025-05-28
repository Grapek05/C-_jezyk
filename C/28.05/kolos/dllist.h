#ifndef DLLIST_H
#define DLLIST_H

#include <stddef.h>

typedef struct node {
    float value;
    struct node *next;
    struct node *prev;
} node;

typedef struct dllist {
    node *head;
    node *tail;
} dllist;

dllist* dllist_new(void);
void dllist_free(dllist *d);

void dllist_append(dllist *d, float value);
void dllist_prepend(dllist *d, float value);

node* dllist_head(dllist *d);
node* dllist_tail(dllist *d);

void dllist_remove(dllist *d, node *n);

size_t dllist_len(const dllist *d);
void dllist_print(const dllist *d);

#endif