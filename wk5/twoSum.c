#include <stdbool.h>
#include <stdio.h>

#include "BST.h"

// return whether there are two numbers in the array that sum to 'sum'
// n = size of the array
// O(n^2) solution
bool hasTwoSum(int *arr, int n, int sum) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == sum) {
				return true;
			}
		}
	}
	return false;
}

// use a binary search tree
bool hasTwoSum(int *arr, int n, int sum) {
	BSTree bst = BSTNew();

	for (int i = 0; i < n; i++) {
		if (BSTSearch(bst, sum - arr[i])) {
			BSTFree(bst);
			return true;
		}
		BSTInsert(bst, arr[i]);
	}

	BSTFree(bst);
	return false;
}
