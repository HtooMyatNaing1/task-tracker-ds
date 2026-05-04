#ifndef STACK_H
#define STACK_H

#include "task.h"

typedef struct Stack {
    Task* top;
} Stack;

// Functions
void initStack(Stack* stack);
void pushUndo(Stack* stack, Task* task);
Task* undo(Stack* stack);
int isUndoEmpty(Stack* stack);
void freeUndoStack(Stack* stack);

#endif