#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "task.h"

void insertTask(Task* task, char* assignee);
Task* deleteTask(char* taskName);
Task* searchTaskList(char* taskName);
void displayTaskList();

#endif