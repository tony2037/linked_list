#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#include "linked_list.h"

int main(int argc, char **argv) {
    struct list_head *head = malloc(sizeof(struct list_head));
    INIT_LIST_HEAD(head);

    uint16_t data [5] = {50, 3, 20, 1, 40};
    for (size_t j = 0; j < 5; ++j) {
        struct listitem *k = malloc(sizeof(struct listitem));
        k->i = data[j];
        INIT_LIST_HEAD(&k->list);
        list_add(&k->list, head);
    }

    display_list(head);
    printf("====================\n");
    list_remove_kth(&head, 3);

    display_list(head);
}
