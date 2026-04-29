# TASK TRACKER – MASTER DEVELOPMENT GUIDE

============================================================
PROJECT OVERVIEW
============================================================

Project Name:
Task Tracker (Data Structure Based CLI System)

Objective:
Build a Task Management System in C using multiple Data Structures that work together in one integrated program.

The system simulates a real workflow:

Backlog (Priority Queue)
↓
Doing List (Linked List)
↓
Undo Stack (Stack)
↓
Back to Doing List (if undone)

Members are tracked separately using:
Binary Search Tree (BST)
Linear Search (for comparison benchmarking)

This project demonstrates:

- Dynamic memory allocation
- Pointer-based structures
- Data structure integration
- Algorithm complexity comparison
- Team-based modular development

============================================================
SYSTEM WORKFLOW
============================================================

1. SYSTEM INITIALIZATION

- enqueueTask()
- insertMemberBST()
- insertMemberLinearly()

2. TASK ASSIGNMENT

- searchMemberBST()
- dequeueTask()
- insertTask()

3. TASK COMPLETION

- deleteTask()
- pushUndo()
- updateMemberBST()

4. UNDO FEATURE

- undo()

5. PERFORMANCE BENCHMARK

- getLinearSearchComparisons()
- getBSTSearchComparisons()

============================================================
DATA STRUCTURES USED
============================================================

Priority Queue → Task Backlog
Linked List → Active Doing List
Stack → Undo System
Binary Search Tree → Member Tracking
Array → Linear Search Comparison

============================================================
CORE STRUCTURES
============================================================

---

## STRUCT TASK (Shared by All)

typedef struct Task {
char name[50];
int id;
int priority;
char assignee[50];
int status; // 0 = active, 1 = completed
struct Task\* next;
} Task;

IMPORTANT RULE:
Task memory is allocated ONLY inside enqueueTask().
Task pointers are passed between queue, list, and stack.
No module creates duplicate Task nodes.

---

---

## STRUCT MEMBER (BST)

typedef struct Member {
char name[50];
int score;
int tasksCompleted;
int free; // 1 = available, 0 = busy
struct Member* left;
struct Member* right;
} Member;

============================================================
HEADER FILE STRUCTURE
============================================================

include/
task.h
queue.h
linkedlist.h
stack.h
bst.h
linear.h

============================================================
FUNCTION PROTOTYPE ORGANIZATION
============================================================

---

## task.h

Contains ONLY struct Task definition.
No functions.

---

## queue.h (Member 1)

void enqueueTask(char* name, int id, int priority);
Task* dequeueTask();
void displayBacklog();

Purpose:
Manage backlog using Priority Queue logic.

---

## linkedlist.h (Member 1)

void insertTask(Task* task, char* assignee);
Task* deleteTask(char* taskName);
Task* searchTaskList(char* taskName);
void displayTaskList();

Purpose:
Manage active tasks.

---

## stack.h (Member 2)

void pushUndo(Task* task);
Task* undo();
int isUndoEmpty();

Purpose:
Undo last completed task.

---

## bst.h (Member 3)

void insertMemberBST(char* name);
Member* searchMemberBST(char* name);
void updateMemberBST(char* name, int points);
void displayMemberBST();
void freeBST();

Purpose:
Track members and contribution scores.

---

## linear.h (Member 3)

void insertMemberLinearly(char* name);
int searchMemberLinearly(char* name);
int getLinearSearchComparisons(char\* name);

Purpose:
Compare performance with BST.

============================================================
MEMBER RESPONSIBILITIES
============================================================

---

## MEMBER 1 – Queue + Linked List

Files:
task.h
queue.c / queue.h
linkedlist.c / linkedlist.h

Responsibilities:

- Define Task struct
- Implement Priority Queue
- Implement Doing List
- Ensure correct pointer movement

---

## MEMBER 2 – Stack + Memory

Files:
stack.c / stack.h

Responsibilities:

- Implement Undo Stack
- Prevent memory leaks
- Handle edge cases
- Implement freeMemory() (if assigned)

Edge Cases to Handle:

- Undo when stack empty
- Pop from empty stack

---

## MEMBER 3 – BST + Linear

Files:
bst.c / bst.h
linear.c / linear.h

Responsibilities:

- Implement BST insertion and search
- Update member score
- Inorder traversal
- Implement linear search
- Implement comparison counting

---

## MEMBER 4 – Integration + CLI

Files:
main.c
benchmark.c (if separate)

Responsibilities:

- Create CLI menu
- Call correct functions
- Connect all modules
- Run performance benchmark

IMPORTANT:
Member 4 does NOT implement data structure logic.
Only integrates and calls functions.

============================================================
TASK FLOW CONTRACT (VERY IMPORTANT)
============================================================

enqueueTask() → creates Task\*

dequeueTask() → returns Task\*

insertTask(Task\*) → moves Task into Doing List

deleteTask() → returns Task\*

pushUndo(Task\*) → moves Task into Stack

undo() → returns Task\*

insertTask() again → restores Task

NO DUPLICATE ALLOCATION.
ONLY MOVE POINTERS.

============================================================
MEMORY RULES
============================================================

- Task created only once.
- No module frees Task individually.
- All memory freed in one cleanup phase.
- BST nodes freed using freeBST().
- Stack and list nodes freed properly.

============================================================
TIME COMPLEXITY
============================================================

Priority Queue:
Enqueue → O(n)
Dequeue → O(1)

Linked List:
Insert → O(1)
Delete → O(n)

Stack:
Push → O(1)
Pop → O(1)

BST:
Average Search → O(log n)
Worst → O(n)

Linear Search:
Search → O(n)

============================================================
GIT WORKFLOW RULES
============================================================

Each member must:

1. Pull latest main
2. Create own branch
3. Work only in assigned files
4. Push branch
5. Create Pull Request
6. Never push directly to main

Example:

git checkout main
git pull origin main
git checkout -b memberX-feature

============================================================
INTEGRATION ORDER
============================================================

1. Member 1 finalizes Task + Queue + List
2. Member 3 finalizes BST + Linear
3. Member 2 finalizes Stack
4. Member 4 integrates everything
5. Full system testing
6. Benchmark demonstration

============================================================
FINAL GOAL
============================================================

This project demonstrates:

- Multi-structure integration
- Pointer-based memory management
- Algorithm comparison
- Real-world workflow simulation
- Professional team collaboration

This is not just coding.
This is system design using Data Structures.
