#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

// create a new empty list
List ListNew() {
	return NULL;
}

// add item to end of list
List ListAdd(List l, int val) {
	// malloc a new node
	List newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = val;

	// if empty list
	if (l == NULL) {
		return newNode;
	}

	// add to end of list
	List curr = l;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newNode;
	return l;
}

// delete the first item with value 'val' from list -- recursively
// if 'val' is not in the list, do nothing
// returns the head of the new linked list
struct node *ListDelete(struct node *l, int val) {
	if (l == NULL) return NULL;
	// if head is value to delete
	if (l->data == val) {
		struct node *newHead = l->next;
		free(l);
		return newHead;
	}

	// i can safely assume that l != NULL AND l->data != val

	struct node *newHeadOfRestOfList = ListDelete(l->next, val);
	l->next = newHeadOfRestOfList;
	return l;
}

// delete all odd numbers from list -- recursively
List ListDeleteOdds(List l) {
	// TODO
	return NULL;
}

// delete every second node (second, fourth, sixth, etc. node)
List ListDeleteSecond(List l) {
	// TODO
	return NULL;
}

// prints out the linked list
void ListPrint(List l) {
	// TODO
}

// prints out the linked list in reverse
void ListPrintReverse(List l) {
	// TODO
}

// returns length of linked list
int ListLength(List l) {
	// TODO
	return 0;
}

// returns number of odd nodes in linked list
int ListCountEvens(List l) {
	// TODO
	return 0;
}

// check if list is sorted in non-descending order
bool ListIsSorted(List l) {
	if (l == NULL || l->next == NULL) return true;

	// bool restOfListSorted = ListIsSorted(l->next);
	// if (!restOfListSorted) return false;
	// if (l->data > l->next->data) return false;
	// return true; // where l->data <= l->next->data and restOfListSorted

	return (l->data <= l->next->data) && ListIsSorted(l->next);
}

// ! THE FOLLOWING TWO EXAMPLES SHOW TWO COMMON TRICKS / TECHNIQUES YOU CAN
// ! USE WHEN CODING RECURSIVELY. TAKE NOTE OF THESE.

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void doListTransform(struct node *l, int position) {
	if (l == NULL) return;

	l->data *= position;
	doListTransform(l->next, position + 1);
}

void ListTransform(struct node *l) {
	doListTransform(l, 1);
}

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void doListTransformAlternate(struct node *l, int *position) {
	if (l == NULL) return;

	l->data *= (*position);
	(*position)++;
	doListTransformAlternate(l, position);
}

void ListTransformAlternate(List l) {
	int position = 1;
	doListTransformAlternate(l, &position);
}
