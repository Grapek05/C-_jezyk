#include <stdio.h>
#include "dllist.h"

int main(void)
{
    dllist *d = dllist_new();
    dllist_append(d, 1.5);
    dllist_append(d, 2.5);
    dllist_prepend(d, -1.5);
    dllist_print(d); // [-1.5, 1.50, 2.50]
    printf("Długość: %zu\n", dllist_len(d));
    
    dllist_remove(d, dllist_head(d));
    dllist_print(d); // [1.50 2.50]

    dllist_remove(d, dllist_tail(d));
    dllist_print(d); // [1.50]
    dllist_free(d);
    return 0;
}

