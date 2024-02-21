#include <stdio.h>
#include <stdlib.h>

// Time Complexity: O(n)
int f1(int n) {
    int sum = 0; 
    for (int i = 0; i < n; i++) { // runs O(n) times
        sum += i % 3; // O(1)
    }
    return sum;
}

// Time Complexity: O(log n)
// the function gets called O(log n) times and takes O(1) to run otherwise
int f2(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + f2(n / 3); 
}

// Time Complexity: O(n log n)
int f3(int n) {
    int count = 0;
    int sum = 0;

    // multiply time complexities because of a 'for each' relationship
    while (count < (n / 2)) { // runs O(n) times
        sum += f2(count); // O(log n) (from above)
        count++;
    }

    return sum;
}

// f1 = O(n)
// f2 = O(log n)
// f3 = O(n log n)
void f4(int n) {
    // Time Complexity: O(n) + O(log n) = O(n)
    // the functions get called one after the other so we add time complexities
    int sum = f1(n) + f2(n);

    // Time Complexity: O(n log n)
    for (int i = 0; i < n; i++) { // runs O(n) times
        f2(i); // O(log n)
    }

    // Time Complexity: O((log n)^2)
    for (int i = 1; i < n; i *= 2) { // runs O(log n) times
        f2(i); // O(log n)
    }

    // Time Complexity: O(n * (n + n log n)) = O(n^2 + n^2 log n) = O(n^2 log n)
    for (int i = 0; i < n; i++) { // O(n)
        f1(i); // O(n)

        // this for loop runs in O(n log n) time
        for (int j = 0; j < n; j++) { // runs O(n) times
            f2(j); // O(log n)
        }
    }

    // Time Complexity: O(n * (n + (log n)^2)) = O(n^2 + n * (log n)^2) = O(n^2)
    // note that O(n) grows (asymptotically) faster than O((log n)^2)
    for (int i = 0; i < n; i++) { // runs O(n) times
        f1(i); // O(n)

        // this for loop runs in O((log n)^2)
        for (int j = 0; j < n; j *= 2) { // O(log n)
            f2(j); // O(log n)
        }
    }

    // Time Complexity: O(n * (n + n * (log n)^2)) = O(n^2 + n^2 * (log n)^2)
    //                = O(n^2 (log n)^2)
    for (int i = 0; i < n; i++) { // runs O(n) times 
        f1(i); // O(n)

        // this for loop runs in O(n * (log n)^2) time
        for (int j = 0; j < n; j *= 2) { // runs O(log n) times
            f3(j); // O(n log n)
        }
    }
}
