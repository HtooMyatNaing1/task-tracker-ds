# Task Tracker System (C Data Structures Project)

## 📖 Project Overview

The **Task Tracker System** is a command-line based task management application developed in C to demonstrate the practical integration of fundamental data structures.

This system simulates a real-world workflow where tasks are:

- Added to a backlog
- Assigned to members
- Marked as completed
- Recovered if completed by mistake
- Tracked for contribution performance

The project emphasizes modular design, memory management, algorithm efficiency, and collaboration among multiple data structure components.

---

## 🎯 Objectives

- Apply core data structures in a unified system
- Compare performance between Binary Search Tree and Linear Search
- Demonstrate proper memory management in C
- Practice modular programming and team collaboration using GitHub

---

## 🧠 Data Structures Used

### 1️⃣ Priority Queue (Backlog Management)

Used to manage incoming tasks based on urgency.

**Functions:**
- `enqueueTask()`
- `dequeueTask()`

Higher urgency tasks are processed first.

---

### 2️⃣ Singly Linked List (Active Task List)

Used to manage tasks currently being worked on.

**Functions:**
- `insertTask()`
- `deleteTask()`
- `displayTask()`

Chosen for dynamic memory flexibility compared to arrays.

---

### 3️⃣ Stack (Undo System)

Implements a Last-In-First-Out (LIFO) structure to allow recovery of mistakenly completed tasks.

**Functions:**
- `pushUndo()`
- `Undo()`
- `freeMemory()`

Instead of permanently deleting completed tasks, they are pushed onto an Undo stack.

---

### 4️⃣ Binary Search Tree (Member Tracking System)

Used to efficiently track and update member contribution scores.

**Functions:**
- `insertMemberBST()`
- `searchMemberBST()`
- `updateMemberBST()`
- `displayMemberBST()`

Inorder traversal is used to print members in sorted order.

---

### 5️⃣ Linear Search (Performance Comparison)

A baseline linear array implementation is included to compare time complexity with the Binary Search Tree.

**Functions:**
- `insertMemberLinearly()`
- `searchMemberLinearly()`
- `updateMemberLinearly()`

Execution time is measured in microseconds for benchmarking.

---

## 🔄 System Workflow

System Initialization
→ enqueueTask()
→ insertMemberBST()

Task Assignment
→ searchMemberBST()
→ dequeueTask()
→ insertTask()

Task Completion & Scoring
→ deleteTask()
→ pushUndo()
→ updateMemberBST()

Mistake Reversal (Optional)
→ Undo()

Performance Benchmarking (Testing Mode)
→ searchMemberLinearly()
→ searchMemberBST()

---

## 🏗 Project Structure

```
task-tracker/
│
├── include/
│   ├── task.h
│   ├── queue.h
│   ├── linkedlist.h
│   ├── stack.h
│   ├── bst.h
│   └── linear.h
│
├── src/
│   ├── main.c
│   ├── queue.c
│   ├── linkedlist.c
│   ├── stack.c
│   ├── bst.c
│   └── linear.c
│
├── benchmark/
│   └── benchmark.c
│
├── Makefile
└── README.md
```
---

## 👥 Team Responsibilities

### Member 1 – Queue + Linked List
- Implement backlog system
- Implement active task list
- Manage shared `Task` structure

### Member 2 – Stack + Memory Management
- Implement Undo system
- Handle memory deallocation
- Prevent memory leaks and handle edge cases

### Member 3 – BST + Linear Search
- Implement Member tracking system
- Manage contribution scoring
- Implement performance comparison logic

### Member 4 – Integration + Benchmark
- Design CLI interface
- Integrate all modules
- Measure execution time
- Compare BST vs Linear Search performance

---

## ⚙️ Compilation & Execution

Using GCC:

```bash
gcc src/*.c -o tasktracker
./tasktracker

make
./tasktracker
