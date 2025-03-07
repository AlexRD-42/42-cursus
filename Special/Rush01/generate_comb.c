#include <stdio.h>
#include <stdlib.h>

/* Utility function to compute factorial of n (assumes n is small enough) */
static int factorial(int n) {
    int f = 1;
    for(int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

/* Swap helper */
static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
  Recursive backtracking function.
  - arr: the current array (1..N) we permute
  - start, end: define the portion of arr to permute
  - result: 2D array to hold permutations
  - idx: index in 'result' at which to store the next permutation
  - N: number of elements
*/
static void backtrack(int *arr, int start, int end, int **result, int *idx, int N) {
    if (start == end) {
        // Copy current permutation into result
        for(int i = 0; i < N; i++) {
            result[*idx][i] = arr[i];
        }
        (*idx)++;
        return;
    }
    for (int i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);
        backtrack(arr, start + 1, end, result, idx, N);
        swap(&arr[start], &arr[i]); // backtrack (undo swap)
    }
}

/*
  Returns a 2D array of all permutations of 1..N.
  - N: the size of the permutation set
  - returnSize: populated with the total number of permutations (N!)
  
  The returned 2D array is allocated on the heap; each row has N elements.
  The caller is responsible for freeing the memory.
*/
int** getAllPermutations(int N, int *returnSize) {
    if (N <= 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Calculate how many permutations (N!)
    *returnSize = factorial(N);
    
    // Allocate space for the permutations
    int **result = (int**)malloc((*returnSize) * sizeof(int*));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = (int*)malloc(N * sizeof(int));
    }
    
    // Prepare an array [1..N] to permute
    int *arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }
    
    // Backtracking approach to fill 'result'
    int idx = 0;
    backtrack(arr, 0, N - 1, result, &idx, N);
    
    free(arr);
    return result;
}

/* Example main to demonstrate usage */
int main(void) {
    int N = 4;
    int returnSize;
    int **perms = getAllPermutations(N, &returnSize);
    
    printf("All permutations of 1..%d:\n", N);
    for(int i = 0; i < returnSize; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", perms[i][j]);
        }
        printf("\n");
    }
    
    /* Free allocated memory */
    for(int i = 0; i < returnSize; i++) {
        free(perms[i]);
    }
    free(perms);
    
    return 0;
}