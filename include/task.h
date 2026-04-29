#ifndef TASK_H
#define TASK_H

typedef struct Task {
    char name[50];
    int id;
    int priority;
    char assignee[50];
    int status;  // 0 = active, 1 = completed
    struct Task* next;
} Task;

#endif