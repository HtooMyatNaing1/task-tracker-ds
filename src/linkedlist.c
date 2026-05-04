#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "task.h"

typedef struct Node {
    Task* task;
    struct Node* next;
} Node;

static Node* head = NULL;

void insertTask(Task* task, char* assignee) {
    strcpy(task->assignee, assignee);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = task;
    newNode->next = head;
    head = newNode;
}

Task* deleteTask(char* taskName) {
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->task->name, taskName) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            Task* deletedTask = current->task;
            free(current);
            return deletedTask;
        }
        prev = current;
        current = current->next;
    }
    return NULL;
}

Task* searchTaskList(char* taskName) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->task->name, taskName) == 0) {
            return current->task;
        }
        current = current->next;
    }
    return NULL;
}

void displayTaskList() {
    Node* current = head;
    while (current != NULL) {
        printf("Task: %s | ID: %d | Assignee: %s | Status: %d | Priority: %d\n",
               current->task->name,
               current->task->id,
               current->task->assignee,
               current->task->status,
               current->task->priority);
        current = current->next;
    }
}
