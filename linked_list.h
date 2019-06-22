#include <stddef.h>
#include <stdint.h>

#include "list.h"


struct listitem {
    uint16_t i;
    struct list_head list;
};

static inline int cmpint(const void *p1, const void *p2);

void list_insert(struct listitem *entry, struct list_head *head);

void list_remove_kth(struct list_head **head, const int k);
