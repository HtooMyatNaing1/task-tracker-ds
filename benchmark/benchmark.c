#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/bst.h"
#include "../include/linear.h"

#define TEST_SIZE 10000

void generateName(char *buffer, int index) {
    sprintf(buffer, "Member_%d", index);
}

int main() {

    char name[50];
    clock_t start, end;
    double bst_time, linear_time;

    printf("=== BENCHMARK TEST ===\n");
    printf("Inserting %d members...\n\n", TEST_SIZE);

    // ----------------------------
    // Insert Members
    // ----------------------------
    for (int i = 0; i < TEST_SIZE; i++) {
        generateName(name, i);
        insertMemberBST(name);
        insertMemberLinearly(name);
    }

    // Target to search (worst-case: last element)
    generateName(name, TEST_SIZE - 1);

    // ----------------------------
    // BST SEARCH TIMING
    // ----------------------------
    start = clock();
    Member* foundBST = searchMemberBST(name);
    end = clock();

    bst_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // ----------------------------
    // LINEAR SEARCH TIMING
    // ----------------------------
    start = clock();
    int foundLinear = searchMemberLinearly(name);
    end = clock();

    linear_time = ((double)(end - start)) / CLOCKS_PER_SEC;

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