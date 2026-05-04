#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Initialize stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Push task
void pushUndo(Stack* stack, Task* task) {
    if (task == NULL) {
        printf("Error: No task to push.\n");
        return;
    }

    task->next = stack->top;
    stack->top = task;

    printf("Task pushed to Undo Stack.\n");
}

// Undo (pop)
Task* undo(Stack* stack) {
    if (stack->top == NULL) {
        printf("Undo Stack is empty.\n");
        return NULL;
    }

    Task* temp = stack->top;
    stack->top = stack->top->next;

    temp->next = NULL;

    printf("Undo successful.\n");
    return temp;
}

// Check empty
int isUndoEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Free memory
void freeUndoStack(Stack* stack) {
    Task* current = stack->top;

    while (current != NULL) {
        Task* temp = current;
        current = current->next;
        free(temp);
    }

    stack->top = NULL;

    printf("Undo Stack memory freed.\n");
}