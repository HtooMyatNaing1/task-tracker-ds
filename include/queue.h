#ifndef QUEUE_H
#define QUEUE_H

#include "task.h"

void enqueueTask(char* name, int id, int priority);
Task* dequeueTask();
void displayBacklog();

#endif