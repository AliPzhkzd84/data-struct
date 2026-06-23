# Data Structures in C++

This repository contains implementations of several basic and advanced data structures in C++. Each project is written independently, with the main goal being to learn and practice data structure concepts through manual implementation (without relying on ready-made STL containers).

## Project List

### 1. Stack (Linked List based)
An implementation of a Stack using a linked list instead of an array. The main operations are `push` (adding to the top of the stack) and `pop` (removing from the top of the stack). The LIFO (Last In, First Out) structure is implemented using a `node` that points to the top of the stack.

### 2. Queue (Linked List based)
An implementation of a Queue using a linked list. Unlike a stack, a queue follows the FIFO (First In, First Out) structure — meaning the first element added is the first one removed.

### 3. Hashing
An implementation of a Hash Table for fast storage and retrieval of data. A hash function maps a key to an index in an array, allowing search, insertion, and deletion to be performed in close to O(1) time.

### 4. AVL Tree
An implementation of an AVL Tree, a type of Binary Search Tree that automatically balances itself. After every `insert` or `delete` operation, the height of subtrees is checked, and if needed, the tree is rebalanced using left, right, or combined rotations. This keeps the search time at O(log n).

### 5. Binary Tree
An implementation of a simple Binary Search Tree without automatic balancing. It includes operations for adding (`add`), deleting (`del`), and searching (`search`) based on comparing values against the tree's nodes.

### 6. Linked List (Circular)
An implementation of a Circular Linked List, where the last node points back to the first node instead of `nullptr`. This structure supports operations such as adding/removing from the beginning, the end, and after a specific node.

### 7. Linked List (Normal)
An implementation of a standard Linear Linked List, where the last node points to `nullptr`. It includes basic operations for adding, deleting, and printing the list.

### 8. Priority Queue
An implementation of a Priority Queue, where each element is ordered and processed based on a priority value, unlike a regular queue which only follows insertion order.

### 9. Stack-based Expression Converter (Stack Arc)
Uses a Stack structure to convert mathematical expressions between Infix notation (the conventional form, e.g. `1+2`) and Postfix notation (e.g. `12+`). This project demonstrates a practical use case of a stack in expression processing.

### 10. Sum & Multiply (Polynomial Linked List)
An implementation of polynomial addition and multiplication using a linked list. Each node represents a term of the polynomial (coefficient and degree), and the `sum` and `multiply` operations perform the corresponding mathematical operations on these terms.

## General Notes

- All projects are written in C++ without using ready-made STL data structure containers (such as `<stack>` or `<queue>`).
- The main purpose of this collection is to practice and gain a deeper understanding of how data structures work from the ground up.
- Each file can be compiled and run independently.

## How to Run

To compile and run any file, use the following command (replacing the file name as needed):

```bash
g++ -o output_name file_name.cpp
./output_name
```