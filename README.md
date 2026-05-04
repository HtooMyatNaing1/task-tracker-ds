# Task Tracker System

Command-line task management system written in C to demonstrate the practical use of fundamental data structures.

## Overview

The application simulates a simple workflow where tasks are added to a backlog, assigned to members, completed, recovered if needed, and tracked for contribution performance.

## Objectives

- Apply core data structures in one unified system
- Compare Binary Search Tree and Linear Search performance
- Demonstrate memory management in C
- Practice modular programming and team collaboration with GitHub

## Data Structures Used

### Priority Queue for backlog management

Used to manage incoming tasks based on urgency.

Functions:

- `enqueueTask()`
- `dequeueTask()`

Higher urgency tasks are processed first.

### Singly linked list for active tasks

Used to manage tasks currently being worked on.

Functions:

- `insertTask()`
- `deleteTask()`
- `displayTask()`

Chosen for dynamic memory flexibility compared to arrays.

### Stack for undo support

Implements a last-in, first-out structure to recover tasks that were completed by mistake.

Functions:

- `pushUndo()`
- `Undo()`
- `freeMemory()`

Instead of permanently deleting completed tasks, they are pushed onto an undo stack.

### Binary Search Tree for member tracking

Used to efficiently track and update member contribution scores.

Functions:

- `insertMemberBST()`
- `searchMemberBST()`
- `updateMemberBST()`
- `displayMemberBST()`

Inorder traversal is used to print members in sorted order.

### Linear search for performance comparison

A baseline linear array implementation is included to compare time complexity with the Binary Search Tree.

Functions:

- `insertMemberLinearly()`
- `searchMemberLinearly()`
- `updateMemberLinearly()`

Execution time is measured in microseconds for benchmarking.

## System Workflow

1. System initialization
   - `enqueueTask()`
   - `insertMemberBST()`
2. Task assignment
   - `searchMemberBST()`
   - `dequeueTask()`
   - `insertTask()`
3. Task completion and scoring
   - `deleteTask()`
   - `pushUndo()`
   - `updateMemberBST()`
4. Mistake reversal, if needed
   - `Undo()`
5. Performance benchmarking
   - `searchMemberLinearly()`
   - `searchMemberBST()`

## Project Structure

```text
task-tracker-ds/
├── include/
│   ├── task.h
│   ├── queue.h
│   ├── linkedlist.h
│   ├── stack.h
│   ├── bst.h
│   └── linear.h
├── src/
│   ├── main.c
│   ├── queue.c
│   ├── linkedlist.c
│   ├── stack.c
│   ├── bst.c
│   └── linear.c
├── benchmark/
│   └── benchmark.c
├── Makefile
└── README.md
```

## Team Responsibilities

| Member   | Responsibilities                                              |
| -------- | ------------------------------------------------------------- |
| Member 1 | Queue and linked list implementation, shared `Task` structure |
| Member 2 | Stack and memory management, deallocation, edge cases         |
| Member 3 | BST and linear search, member scoring, performance comparison |
| Member 4 | CLI integration, module integration, benchmarking             |

## Compilation and Execution

Using GCC:

```bash
gcc src/*.c -o tasktracker
./tasktracker
```

Using Make:

```bash
make
./tasktracker
```
