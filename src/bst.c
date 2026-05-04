#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

Member* root = NULL;

Member* createMember(char* name) {
    Member* newNode = (Member*)malloc(sizeof(Member));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(newNode->name, name);
    newNode->score = 0;
    newNode->tasksCompleted = 0;
    newNode->free = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insertMemberBST(char* name) {
    Member* newNode = createMember(name);

    if (root == NULL) {
        root = newNode;
        return;
    }

    Member* current = root;
    Member* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (strcmp(name, current->name) < 0)
            current = current->left;
        else if (strcmp(name, current->name) > 0)
            current = current->right;
        else {
            printf("Member already exists!\n");
            free(newNode);
            return;
        }
    }

    if (strcmp(name, parent->name) < 0)
        parent->left = newNode;
    else
        parent->right = newNode;
}

Member* searchMemberBST(char* name) {
    Member* current = root;

    while (current != NULL) {
        int cmp = strcmp(name, current->name);

        if (cmp == 0)
            return current;
        else if (cmp < 0)
            current = current->left;
        else
            current = current->right;
    }

    return NULL;
}

void updateMemberBST(char* name, int points) {
    Member* member = searchMemberBST(name);

    if (member == NULL) {
        printf("Member not found!\n");
        return;
    }

    member->score += points;
    member->tasksCompleted += 1;
}

void inorderTraversal(Member* node) {
    if (node == NULL)
        return;

    inorderTraversal(node->left);

    printf("Name: %s | Score: %d | Tasks: %d | Status: %s\n",
           node->name,
           node->score,
           node->tasksCompleted,
           node->free ? "Free" : "Busy");

    inorderTraversal(node->right);
}

void displayMemberBST() {
    if (root == NULL) {
        printf("No members in system.\n");
        return;
    }

    printf("\n=== MEMBER ROSTER (BST - Sorted) ===\n");
    inorderTraversal(root);
}

void freeBSTHelper(Member* node) {
    if (node == NULL)
        return;

    freeBSTHelper(node->left);
    freeBSTHelper(node->right);
    free(node);
}

void freeBST() {
    freeBSTHelper(root);
    root = NULL;
}