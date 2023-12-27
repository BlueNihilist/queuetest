#include <sys/queue.h>
#include <stdio.h>
#include <stdlib.h>

LIST_HEAD(listhead, entry) head;
struct listhead *headp;         /* заголовок списка */
struct entry {
        LIST_ENTRY(entry) entries;      /* список */
        int data;
} *n1, *n2, *np;

void lprint(struct listhead *head) {
        struct entry *iter = NULL;
        LIST_FOREACH(iter, head, entries) {
                printf("%d ", iter->data);
        }
        printf("\n");
}

void lclean(struct listhead *head) {
        while (head->lh_first != NULL) {
                LIST_REMOVE(head->lh_first, entries);
        }
}

int main(void) {
        LIST_INIT(&head);

        n1 = malloc(sizeof(struct entry));
        n1->data = 1;
        LIST_INSERT_HEAD(&head, n1, entries);

        n2 = malloc(sizeof(struct entry));
        n2->data = 2;
        LIST_INSERT_AFTER(n1, n2, entries);
        lprint(&head);

        LIST_REMOVE(head.lh_first, entries);
        lprint(&head);
        
        lclean(&head);
        lprint(&head);
        return 0;
}