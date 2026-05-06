# 📌 Task Management System (C Language)

## 📖 Overview

This project is a modular **Task Management System** implemented in C using fundamental data structures.

The system manages:
- Team members
- Task assignments
- Backlog handling
- Undo operations
- Performance comparison between search algorithms

Each feature is separated into independent modules to support clean architecture and collaborative development.

---

## 🚀 Features

- Member management using **Binary Search Tree (BST)**
- Linear search implementation for performance comparison
- Task management using **Linked List**
- Backlog system using **Queue (FIFO)**
- Undo functionality using **Stack (LIFO)**
- Modular design for team-based development

---

## 🏗 Data Structure Design

### 1️⃣ Binary Search Tree (BST)

Used to store and manage team members in sorted order.

- Average search complexity: O(log n)
- Efficient insertion
- Supports updates and traversal display

---

### 2️⃣ Linear Search

Used to compare search performance with BST.

- Sequential search (O(n))
- Counts number of comparisons
- Used for benchmarking

---

### 3️⃣ Linked List

Stores active tasks dynamically.

- Dynamic memory allocation
- Easy insertion and deletion
- Supports task reassignment

---

### 4️⃣ Queue (Backlog)

Handles pending tasks.

- First-In-First-Out (FIFO)
- Stores tasks waiting to be assigned

---

### 5️⃣ Stack (Undo System)

Supports undo operations.

- Last-In-First-Out (LIFO)
- Reverts recent task operations

---

## 📂 Project Structure

```
project-root/
│
├── docs/
│   ├──members_read.md
│   ├──team_master_guide.md
│
├── include/
│   ├── bst.h
│   ├── linear.h
│   ├── linkedlist.h
│   ├── queue.h
│   ├── stack.h
│   ├── task.h
│
├── src/
│   ├── bst.c
│   ├── linear.c
│   ├── linkedlist.c
│   ├── main.c (Main Menu)
│   ├── queue.c
│   ├── stack.c
│
├── LICENSE
├── Makefile
├── README.md
```

---

## 👥 Team Responsibilities

### Member 1
- Queue implementation
- Linked List implementation

### Member 2
- Stack implementation
- Memory management handling

### Member 3 (Project Lead)
- Binary Search Tree (BST)
- Linear Search implementation
- Performance comparison logic

### Member 4
- System integration
- Main program development
- Final testing and debugging

---

## 🔧 Build Instructions

### Compile

```bash
gcc -Iinclude -o <output>.exe .\src\linear.c .\src\stack.c .\src\queue.c .\src\linkedlist.c .\src\bst.c .\src\main.c
```

### Run

```bash
./<output>.exe
```

---

### Compile Using Makefile

```bash
make
```

### Run

```bash
./<output>.exe
```

---

## 🌿 Git Workflow

Each member works on their own feature branch:

- Member1-Queue+Linklisted
- member2
- Member3
- Member4-CLI

### Development Process

1. Implement assigned module
2. Test independently
3. Push to personal branch
4. Create Pull Request
5. Merge after review

---

## 📊 Benchmark Purpose

This project compares:

- BST search efficiency
- Linear search efficiency

Metrics collected:

- Search success
- Number of comparisons
- Performance difference

---

## 🔮 Future Improvements

- File persistence (save/load system state)
- Priority-based task sorting
- Full performance report output
- Improved CLI menu system
- Enhanced error handling

---

## 🧠 Educational Purpose

This project demonstrates practical usage of:

- Dynamic memory allocation
- Pointers and structures
- Multiple data structures integration
- Modular programming in C
- Collaborative Git workflow
