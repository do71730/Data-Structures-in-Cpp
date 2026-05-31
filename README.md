# Introduction

This project explores several fundamental data structures implemented manually in C++.  
The main goal is to understand how these structures work internally **without using their standard library equivalents**.

## Components of the Project
- **container_structure.h** — Contains class definitions and function declarations for container structures. 
- **main.cpp** — Test cases (some generated using GitHub Copilot).
- **tree_structure.h** — **Future Implementation** Contains class definitions and function declarations for tree structures. 

## Implemented Data Structures
- **Stack** — A LIFO structure that allows pushing and popping from the top.  
  Indexing is not allowed in typical stacks, but this project includes a custom sort function.

- **Queue** — A FIFO structure that allows pushing to the back and popping from the front.  
  Like stacks, indexing is normally not allowed, but sorting is supported here.

- **Deque** — A double‑ended queue that allows insertion and removal from both ends.  
  Indexing and sorting are supported.

## Available Functions

The following functions are implemented in `container_structure.h`:

| Function | Description | Stack | Queue | Deque |
|---------|-------------|-------|--------|--------|
| `empty()` | Check if the structure is empty | yes | yes | yes |
| `push_back(num)` | Push a number to the back/top | `push(num)` | `push(num)` | `push_back(num)` |
| `push_front(num)` | Push a number to the front | - | - | yes |
| `pop_back()` | Remove an element from the back | `pop()` | - | `pop_back()` |
| `pop_front()` | Remove an element from the front | - | `pop()` | `pop_front()` |
| `display()` | Print the structure | yes | yes | yes |
| `sort()` | Sort the structure | yes | yes | yes |
| `erase(index)` | Remove element at a given index | - | - | yes |
| `deleted()` | Remove all elements | yes | yes | yes |
| `front()` | Return the front element | - | yes | yes |
| `back()` | Return the back element | `top()` | `front()` | `front()` |
| `operator[]` | Access element by index | - | - | yes |
| `at()` | Access element by index with bounds checking | - | - | yes |
| `size()` | Return the number of elements | yes | yes | yes |

## Techniques Used
- Classes & Object‑Oriented Design  
- Inheritance  
- Access Specifiers  
- Custom Header Files  
- Pointers & References  
- Memory Leak Detection  
- Exception Handling  
- Operator Overloading  

## Example Usage

Below are short examples demonstrating how to use the **Stack**, **Queue**, and **Deque** structures implemented in `container_structure.h`.

```cpp
#include "container_structure.h"
#include <iostream>
using namespace std;

int main() {
    // -------------------------
    // Stack Example
    // -------------------------
    stack s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);

    cout << "Stack: ";
    s.display();

    s.pop_back();
    cout << "After pop_back: ";
    s.display();

    s.sort();
    cout << "After sort: ";
    s.display();


    // -------------------------
    // Queue Example
    // -------------------------
    queue q;
    q.push_back(5);
    q.push_back(15);
    q.push_back(25);

    cout << "\nQueue: ";
    q.display();

    q.pop_front();
    cout << "After pop_front: ";
    q.display();


    // -------------------------
    // Deque Example
    // -------------------------
    dequeue d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(0);

    cout << "\nDeque: ";
    d.display();

    d.pop_front();
    d.pop_back();
    cout << "After pops: ";
    d.display();

    d.push_back(10);
    d.push_back(20);
    d.sort();
    cout << "After sort: ";
    d.display();

    cout << "Index 0: " << d[0] << "\n";
    cout << "Index 1 (at): " << d.at(1) << "\n";

    return 0;
}

