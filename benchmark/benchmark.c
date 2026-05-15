#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/bst.h"
#include "../include/linear.h"

#define TEST_SIZE 10000
// Number of repeated searches to average timing results
#define REPEATS 1000

void generateName(char *buffer, int index) {
    sprintf(buffer, "Member_%d", index);
}

int main() {

    char name[50];
    clock_t start, end;
    double bst_time, linear_time;

    printf("=== BENCHMARK TEST ===\n");
    printf("Inserting %d members (randomized)...\n\n", TEST_SIZE);

    // Create randomized insertion order to avoid degenerate BST
    int *indices = (int *)malloc(sizeof(int) * TEST_SIZE);
    if (!indices) {
        fprintf(stderr, "Failed to allocate indices array\n");
        return 1;
    }

    for (int i = 0; i < TEST_SIZE; i++)
        indices[i] = i;

    srand((unsigned)time(NULL));
    for (int i = TEST_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = indices[i];
        indices[i] = indices[j];
        indices[j] = tmp;
    }

    // ----------------------------
    // Insert Members (random order)
    // ----------------------------
    for (int k = 0; k < TEST_SIZE; k++) {
        int i = indices[k];
        generateName(name, i);
        insertMemberBST(name);
        insertMemberLinearly(name);
    }

    free(indices);

    // Target to search (worst-case: last element)
    generateName(name, TEST_SIZE - 1);

    // ----------------------------
    // BST SEARCH TIMING (averaged)
    // ----------------------------
    start = clock();
    Member* foundBST = NULL;
    for (int r = 0; r < REPEATS; r++) {
        foundBST = searchMemberBST(name);
    }
    end = clock();

    bst_time = (((double)(end - start)) / CLOCKS_PER_SEC) / REPEATS;

    // ----------------------------
    // LINEAR SEARCH TIMING (averaged)
    // ----------------------------
    start = clock();
    int foundLinear = -1;
    for (int r = 0; r < REPEATS; r++) {
        foundLinear = searchMemberLinearly(name);
    }
    end = clock();

    linear_time = (((double)(end - start)) / CLOCKS_PER_SEC) / REPEATS;

    // ----------------------------
    // RESULTS
    // ----------------------------
    printf("Search Target: %s\n\n", name);

    printf("BST Search Result: %s\n", foundBST ? "Found" : "Not Found");
    printf("BST Search Time: %.8f seconds\n\n", bst_time);

    printf("Linear Search Result: %s\n", foundLinear ? "Found" : "Not Found");
    printf("Linear Search Time: %.8f seconds\n", linear_time);
    printf("Linear Search Comparisons: %d\n",
           getLinearSearchComparisons(name));

    freeBST();

    return 0;
}