#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

// delete the first instance of node with 'value' from the linked list
// returns the head of the linked list after this is complete
struct node *listDelete(struct node *list, int value) {
	struct node *curr = list;

	if (curr == NULL) return NULL;

	if (curr->value == value) {
		struct node *newHead = curr->next;
		free(curr);
		return newHead;
	}

	while (curr->next != NULL) {
		if (curr->next->value == value) {
			struct node *tmp = curr->next->next;
			free(curr->next);
			curr->next = tmp;
		}
	}

	return list;
}
