#ifndef STACK_H
#define STACK_H

#include "task.h"

void pushUndo(Task* task);
Task* undo();
int isUndoEmpty();
void freeUndoStack();

#endif