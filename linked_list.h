#include <stddef.h>
#include <stdint.h>

#include "list.h"


struct listitem {
    uint16_t i;
    struct list_head list;
};

void list_insert(struct listitem *entry, struct list_head **head);

void list_remove_kth(struct list_head **head, const int k);

void display_list(struct list_head *head);

int partition_right(struct list_head **head, const int right);

int partition_left(struct list_head **head, const int left);
