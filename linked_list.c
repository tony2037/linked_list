#include <stdlib.h>

#include "linked_list.h"

static inline int cmpint(const void *p1, const void *p2) {
    const uint16_t *i1 = (const uint16_t *) p1;
    const uint16_t *i2 = (const uint16_t *) p2;
    return *i1 - *i2;
}

void list_insert(struct listitem *entry, struct list_head *head) {
    if (list_empty(head)) {
        list_add(&entry->list, head);
        return;
    }

    struct listitem *p = NULL;
    list_for_each_entry(p, head, list) {
        if (cmpint((void *) &entry->i, (void *) &p->i)) {
            list_add(&entry->list, &p->list);
            return;
        }
    }
    list_add_tail(&entry->list, head);
}

void list_remove_kth(struct list_head **head, const int k) {
    struct list_head sorted;
    INIT_LIST_HEAD(&sorted);
    struct listitem *p = NULL;
    struct listitem *n = NULL;
    list_for_each_entry_safe(p, n, *head, list) {
        struct listitem *e = malloc(sizeof(struct listitem));
        e->i = p->i;
        INIT_LIST_HEAD(&e->list);
        list_insert(e, &sorted);
    }

    size_t i = k;
    p = NULL;
    n = NULL;
    uint16_t target = 0; 
    list_for_each_entry_safe(p, n, &sorted, list) {
        if(!i--) {
            target = p->i;
        }
    }

    p = NULL;
    n = NULL;
    list_for_each_entry_safe(p, n, *head, list) {
        if(target == p->i) {
            if(&p->list == *head) {
                *head = &p->list.next;
            }
            list_del(&p->list);
        }
    }
}
