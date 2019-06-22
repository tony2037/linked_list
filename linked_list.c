#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

void display_list(struct list_head *head) {
    struct listitem *p = NULL;
    list_for_each_entry(p, head, list) {
        printf("%u\n", p->i);
    }
}

static inline int cmpint(const void *p1, const void *p2) {
    const uint16_t *i1 = (const uint16_t *) p1;
    const uint16_t *i2 = (const uint16_t *) p2;
    return *i1 - *i2;
}

void list_insert(struct listitem *entry, struct list_head **head) {
    if (list_empty(*head)) {
        list_add(&entry->list, *head);
        return;
    }

    struct listitem *p = NULL;
    struct list_head *insert = *head;
    list_for_each_entry(p, *head, list) {
        if (entry->i < p->i) {
            insert = &p->list;
            continue;
        }
    }
    list_add(&entry->list, insert);
}

void list_remove_kth(struct list_head **head, const int k) {
}
