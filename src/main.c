#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "queue.h"
#include "linkedlist.h"
#include "stack.h"
#include "bst.h"
#include "linear.h"

#define NAME_LEN 50

static Stack undoStack;

static void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        ;
    }
}

static void readString(char* buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\r\n")] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

static void ensureMemberExists(const char* name) {
    if (searchMemberBST((char*)name) == NULL) {
        insertMemberBST((char*)name);
        insertMemberLinearly((char*)name);
    }
}

static void reverseMemberUpdate(const char* name, int points) {
    Member* member = searchMemberBST((char*)name);
    if (member == NULL) {
        return;
    }

    member->score -= points;
    if (member->tasksCompleted > 0) {
        member->tasksCompleted -= 1;
    }
}

static void addTaskToBacklog() {
    char name[NAME_LEN];
    int id;
    int priority;

    printf("\nEnter task name: ");
    readString(name, NAME_LEN);
    if (name[0] == '\0') {
        printf("Task name cannot be empty.\n");
        return;
    }

    printf("Enter task ID: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("Invalid ID. Task not added.\n");
        return;
    }
    clearInputBuffer();

    printf("Enter task priority (higher number = higher urgency): ");
    if (scanf("%d", &priority) != 1) {
        clearInputBuffer();
        printf("Invalid priority. Task not added.\n");
        return;
    }
    clearInputBuffer();

    enqueueTask(name, id, priority);
    printf("Task '%s' has been added to the backlog.\n", name);
}

static void initTaskBacklog() {
    int choice = 0;

    printf("\n========================================\n");
    printf("   SYSTEM INITIALIZATION: TASK BACKLOG\n");
    printf("========================================\n");

    while (choice != 2) {
        printf("\n1. Enqueue a new task\n");
        printf("2. Finish adding tasks and proceed\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\n[!] Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        if (choice == 1) {
            addTaskToBacklog();
        } else if (choice != 2) {
            printf("\n[!] Invalid choice. Please press 1 or 2.\n");
        }
    }
}

static void addTeamMember() {
    char name[NAME_LEN];

    printf("\nEnter new member name: ");
    readString(name, NAME_LEN);
    if (name[0] == '\0') {
        printf("Member name cannot be empty.\n");
        return;
    }

    if (searchMemberBST(name) != NULL) {
        printf("Member '%s' already exists.\n", name);
        return;
    }

    insertMemberBST(name);
    insertMemberLinearly(name);
    printf("Member '%s' was added to the roster.\n", name);
}

static void assignNextBacklogTask() {
    Task* task = dequeueTask();
    if (task == NULL) {
        printf("\nNo tasks in backlog to assign.\n");
        return;
    }

    char assignee[NAME_LEN];
    printf("\nAssigning task '%s' (ID %d, priority %d)\n", task->name, task->id, task->priority);
    printf("Enter assignee name: ");
    readString(assignee, NAME_LEN);
    if (assignee[0] == '\0') {
        strcpy(assignee, "Unassigned");
    }

    ensureMemberExists(assignee);
    insertTask(task, assignee);
    printf("Task '%s' has been assigned to %s.\n", task->name, assignee);
}

static void completeTask() {
    char taskName[NAME_LEN];

    printf("\nEnter the name of the task to complete: ");
    readString(taskName, NAME_LEN);
    if (taskName[0] == '\0') {
        printf("Task name cannot be empty.\n");
        return;
    }

    Task* task = deleteTask(taskName);
    if (task == NULL) {
        printf("Task '%s' not found in active tasks.\n", taskName);
        return;
    }

    task->status = 1;
    pushUndo(&undoStack, task);

    if (strcmp(task->assignee, "Unassigned") != 0) {
        ensureMemberExists(task->assignee);
        updateMemberBST(task->assignee, task->priority);
    }

    printf("Task '%s' completed and pushed to Undo stack.\n", task->name);
}

static void undoLastCompletedTask() {
    Task* task = undo(&undoStack);
    if (task == NULL) {
        return;
    }

    if (strcmp(task->assignee, "Unassigned") != 0) {
        reverseMemberUpdate(task->assignee, task->priority);
    }

    task->status = 0;
    insertTask(task, task->assignee);
    printf("Task '%s' restored to active list.\n", task->name);
}

static void searchActiveTask() {
    char taskName[NAME_LEN];

    printf("\nEnter task name to search: ");
    readString(taskName, NAME_LEN);
    if (taskName[0] == '\0') {
        printf("Task name cannot be empty.\n");
        return;
    }

    Task* task = searchTaskList(taskName);
    if (task == NULL) {
        printf("Task '%s' not found in the active task list.\n", taskName);
        return;
    }

    printf("\nFound task:\n");
    printf("Name: %s\n", task->name);
    printf("ID: %d\n", task->id);
    printf("Priority: %d\n", task->priority);
    printf("Assignee: %s\n", task->assignee);
    printf("Status: %s\n", task->status == 0 ? "Active" : "Completed");
}

int main() {
    int choice = -1;
    initStack(&undoStack);

    printf("Welcome to the Task Tracker System!\n");
    initTaskBacklog();

    while (choice != 0) {
        printf("\n============================\n");
        printf("Task Tracker Main Menu\n");
        printf("============================\n");
        printf("1. Add task to backlog\n");
        printf("2. View task backlog\n");
        printf("3. Add team member\n");
        printf("4. View member roster\n");
        printf("5. Assign next backlog task\n");
        printf("6. View active tasks\n");
        printf("7. Complete active task\n");
        printf("8. Undo last completed task\n");
        printf("9. Search active task\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addTaskToBacklog();
                break;
            case 2:
                printf("\n=== Backlog Tasks ===\n");
                displayBacklog();
                break;
            case 3:
                addTeamMember();
                break;
            case 4:
                displayMemberBST();
                break;
            case 5:
                assignNextBacklogTask();
                break;
            case 6:
                printf("\n=== Active Tasks ===\n");
                displayTaskList();
                break;
            case 7:
                completeTask();
                break;
            case 8:
                undoLastCompletedTask();
                break;
            case 9:
                searchActiveTask();
                break;
            case 0:
                printf("Exiting Task Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid menu option.\n");
                break;
        }
    }

    freeUndoStack(&undoStack);
    freeBST();
    return 0;
}
