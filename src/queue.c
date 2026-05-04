#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "task.h"

typedef struct QNode {
    Task* task;
    struct QNode* next;
} QNode;

static QNode* front = NULL;
static QNode* rear = NULL;

void enqueueTask(char* name, int id, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->id = id;
    newTask->priority = priority;
    newTask->status = 0;
    strcpy(newTask->assignee, "Unassigned");
    newTask->next = NULL;

    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->task = newTask;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Task* dequeueTask() {
    if (front == NULL) {
        return NULL;
    }
    QNode* temp = front;
    Task* task = temp->task;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return task;
}

void displayBacklog() {
    QNode* current = front;
    while (current != NULL) {
        printf("Task: %s | ID: %d | Priority: %d | Status: %d\n",
               current->task->name,
               current->task->id,
               current->task->priority,
               current->task->status);
        current = current->next;
    }
}
