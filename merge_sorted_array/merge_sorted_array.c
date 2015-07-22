/* Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
you may assume that a has enough space (size that is greater or equal to m + n) to hold
additional elements from B. The number of elements initialized in A and B are m and n respectively.*/

#include <assert.h>
#include <stdio.h>

void print_array(int* A, int size) {
    int i;

    for (i = 0; i < size; ++i) {
        if (i) {
            printf(" ");
        }

        printf("%d", A[i]);
    }
}

/* Helper function to swap the elements of two arrays */
void swap(int* A, int i, int* B, int j) {
    // We should check for NULL pointers and bounds, but
    // ignore them here for speed
    int temp = A[i];
    A[i] = B[j];
    B[j] = temp;
}

/* Running time should be O(m + n) (true for average and best
 * cases as well since the merging needs to process all elements
 *
 * This approach uses no auxillary space by using the "excess" space
 * in A to temporarily store elements as they are swapped into their
 * appropriate places */
void merge(int *a, int m, int *b, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (a[i] > b[j]) {
            a[k--] = a[i--];
        } else {
            a[k--] = b[j--];
        }
    }

    while (j >= 0) {
        a[k--] = b[j--];
    }
}

int main() {
    int A[] = { 1, 4, 5, 0, 0 };
    int B[] = { 2, 3, 0, 0, 0 };
    int m   = 3, n = 2;
    int i;

    print_array(A, m + n);
    printf("\n");
    print_array(B, n);
    printf("\n");

    merge(A, m, B, n);

    print_array(A, m + n);
    printf("\n");
    print_array(B, n);
    printf("\n");
    
    // Sanity check
    for (i = 1; i < m + n; ++i) {
        assert(A[i-1] <= A[i]);
    }

    // Same check, but now B is larger than A
    m = 2;
    A[0] = -1;
    A[1] = 8;
    A[2] = 0;
    A[3] = 0;
    A[4] = 0;
    
    n = 3;
    B[0] = -2;
    B[1] = 9;
    B[2] = 10;

    print_array(A, m + n);
    printf("\n");
    print_array(B, n);
    printf("\n");

    merge(A, m, B, n);

    print_array(A, m + n);
    printf("\n");
    print_array(B, n);
    printf("\n");

    for (i = 1; i < m + n; ++i) {
        assert(A[i-1] <= A[i]);
    }

    // Randomised sanity check
}
