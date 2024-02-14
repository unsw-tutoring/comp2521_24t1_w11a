#include <stdio.h>
#include <stdlib.h>

// modify this to use malloc instead of creating on the stack
struct node {
	int value;
	struct node *next;
};

int main(void) {
	struct node n;
	n.value = 42;
	n.next = NULL;

	struct node *n2 = malloc(sizeof(struct node));
	// struct node *n2 = malloc(sizeof(*n2));
	n2->value = 42;
	n2->next = NULL;
}

// modify this to use malloc instead of creating on the stack
int main(void) {
	int a[5];
	for (int i = 0; i < 5; i++) {
		a[i] = 42;
	}

	int *array = malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++) {
		array[i] = 42;
	}
}
