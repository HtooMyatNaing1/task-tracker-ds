# TASK TRACKER PROJECT – TEAM DEVELOPMENT GUIDE

---

# 1. PROJECT OVERVIEW

## Project Title

Task Tracker (Data Structure Based CLI System)

## Objective

This project is a command-line Task Management System implemented in C using multiple core Data Structures.

The system workflow:

- Tasks stored in Backlog (Priority Queue)
- Assigned tasks stored in Doing List (Linked List)
- Completed tasks stored temporarily in Undo Stack
- Members tracked using Binary Search Tree
- Performance compared using Linear Search vs BST

This project demonstrates:

- Dynamic memory allocation
- Data structure integration
- Algorithm comparison
- System design thinking

---

# 2. SYSTEM WORKFLOW

System Initialization:

- enqueueTask()
- insertMemberBST()
- insertMemberLinearly()

Task Assignment:

- searchMemberBST()
- dequeueTask()
- insertTask()

Task Completion:

- deleteTask()
- pushUndo()
- updateMemberBST()

Undo Action:

- undo()

Performance Benchmark:

- searchMemberLinearly()
- searchMemberBST()
- Compare number of comparisons

---

# 3. DATA STRUCTURES USED

Priority Queue → Backlog  
Singly Linked List → Doing List  
Stack → Undo system  
Binary Search Tree → Member tracking  
Array → Linear search comparison

---

# 4. UNIFIED TASK STRUCTURE

All task-related modules MUST use the same struct.

struct Task {
char name[50];
int id;
int priority;
char assignee[50];
int status; // 0 = active, 1 = completed
struct Task\* next;
};

Purpose:

- Avoid duplicate task objects
- Allow smooth integration between queue, list, and stack
- Improve memory efficiency

---

# 5. MEMBER RESPONSIBILITIES

========================================
MEMBER 1 – Queue + Linked List
========================================

Responsibilities:

- Define struct Task
- Implement Priority Queue
- Implement Singly Linked List

Priority Queue Functions:

enqueueTask()
Purpose:
Insert task into backlog based on priority (higher priority first).

dequeueTask()
Purpose:
Remove highest priority task from backlog.
Return pointer to Task.

Linked List Functions:

insertTask(struct Task* task, char* assignee)
Purpose:
Insert assigned task into Doing List.
Update task->assignee.

deleteTask(char\* taskName)
Purpose:
Remove task when completed.
Return pointer to removed task (important for Undo).

displayTask()
Purpose:
Display all active tasks.

---

========================================
MEMBER 2 – Stack + Memory Management
========================================

Responsibilities:

- Implement Undo Stack
- Prevent memory leaks
- Handle edge cases
- Implement freeMemory()

Stack Functions:

pushUndo(struct Task\* task)
Purpose:
Push completed task onto stack.

undo()
Purpose:
Pop last completed task and reinsert into Doing List.

Memory Management:

freeMemory()
Purpose:
Free all allocated memory:

- Backlog
- Doing List
- Stack
- BST

---

========================================
MEMBER 3 – BST + Linear Search
========================================

Responsibilities:

- Implement struct Member
- Implement BST operations
- Implement Linear search
- Provide comparison-count functions

Member Structure:

struct Member {
char name[50];
int score;
int tasksCompleted;
int free; // 1 = available, 0 = busy
struct Member* left;
struct Member* right;
};

BST Functions:

insertMemberBST()
Insert member alphabetically by name.

searchMemberBST()
Search member by name.
Return pointer.

updateMemberBST(char\* name, int points)
Increase member contribution score.

displayMemberBST()
Display members using Inorder traversal (sorted order).

Linear Search Functions:

insertMemberLinearly()
Insert member into array.

searchMemberLinearly()
Search one by one through array.

getLinearSearchComparisons()
Return number of comparisons made.

getBSTSearchComparisons()
Return number of comparisons in BST search.

---

========================================
MEMBER 4 – Integration + CLI + Benchmark
========================================

Responsibilities:

- Implement CLI main menu
- Connect all modules
- Call correct functions
- Run performance benchmark

Main CLI:

mainMenu()
Handles:

1. View backlog
2. View member roster
3. Assign task
4. Check task status
5. Mark task completed
6. View performance
7. Linear search
8. BST search
9. Benchmark
10. Exit

Benchmark:

benchmarkSearches()
Compare:

- Linear Search comparisons
- BST comparisons

Display:

- Number of operations
- Which structure is more efficient

---

# 6. GIT WORKFLOW RULES

Each member must:

1. Pull latest main
2. Create own branch
3. Commit only to own branch
4. Push branch
5. Create Pull Request
6. Never push directly to main

Example:
git checkout main
git pull origin main
git checkout -b memberX-feature

---

# 7. INTEGRATION ORDER

1. Member 1 finalizes Task struct
2. Member 3 finalizes Member struct
3. Member 2 completes Stack
4. Member 4 integrates system
5. Testing phase
6. Benchmark testing
7. Final merge

---

# FINAL GOAL

This project demonstrates:

- Data structure integration
- Memory management
- Algorithm efficiency comparison
- Real-world workflow simulation
- Team-based software development
