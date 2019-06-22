#include <stdlib.h>
#include "list.h"

#include "linked_list.h"

int main(int argc, char **argv) {
    struct list_head head;
    INIT_LIST_HEAD(&head);

    uint16_t data [5] = {5, 3, 2, 1, 4};
    for (size_t j = 0; j < 5; ++j) {
        struct listitem *k = malloc(sizeof(struct listitem));
        k->i = data[j];
        INIT_LIST_HEAD(&k->list);
        list_insert(k, &head);
    }

    display_list(&head);
}
