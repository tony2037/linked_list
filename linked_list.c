#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

void display_list(struct list_head *head) {
    struct listitem *p = NULL;
    list_for_each_entry(p, head, list) {
        printf("%u\n", p->i);
    }
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

int partition_right(struct list_head **head, const int right) {
    uint16_t pivot = container_of((*head)->next, struct listitem, list)->i;
    int i = 0;
    int j = 0;
    struct listitem *p = NULL;
    struct listitem *n = NULL;
    list_for_each_entry_safe(p, n, *head, list) {
        if(p->i > pivot) {
            list_move_tail(&p->list, *head);
            ++j;
        }
        if(++i == right) return j;
    }
    return 0;
}

void list_remove_kth(struct list_head **head, const int k) {
    struct list_head *tmp = malloc(sizeof(struct list_head));
    INIT_LIST_HEAD(tmp);
    struct listitem *p = NULL;
    struct listitem *n = NULL;
    list_for_each_entry_safe(p, n, *head, list) {
        list_del(&p->list);
        list_insert(p, &tmp);
    }
    int i = 0;
    list_for_each_entry_safe(p, n, tmp, list) {
        if(++i == k) {
            list_del(&p->list);
            continue;
        }
        list_move(&p->list, *head);
    }
/*
    uint16_t pivot = container_of((*head)->next, struct listitem, list)->i;
    int target = k - 1;
    int total_size = 0;
    int j = 0;
    struct listitem *p = NULL;
    struct listitem *n = NULL;
    list_for_each_entry_safe(p, n, *head, list) {
        if(p->i > pivot) {
            list_move_tail(&p->list, *head);
            ++j;
        }
        ++total_size;
    }
    while(j != target){
        if (j < target) {
            j += partition_right(head, total_size - j);
        }
        else if (j > target) {
        }
    }
    list_del((*head)->next);
*/

/*
    struct listitem *i = container_of((*head)->next, struct listitem, list);
    printf("%u\n", i->i);
    list_del((*head)->next->next);
    i = container_of((*head)->next, struct listitem, list);
    printf("%u\n", i->i);
*/
}
