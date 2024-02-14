#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
};

// delete the first instance of node with 'value' from the linked list
void listDelete(struct list *list, int value) {
	struct node *curr = list->head;

	if (curr == NULL) return NULL;

	if (curr->value == value) {
		struct node *newHead = curr->next;
		free(curr);
		list->head = newHead;
		return;
	}

	while (curr->next != NULL) {
		if (curr->next->value == value) {
			struct node *tmp = curr->next->next;
			free(curr->next);
			curr->next = tmp;
		}
	}
}
