# STL (Custom C++ Standard Template Library)

A from-scratch C++ template library that reimplements core STL-style containers, iterators, algorithms, and smart pointers under the `rub` namespace.

## Overview

This project focuses on low-level C++ engineering by rebuilding standard library concepts manually, including:

- Generic programming with templates
- Manual memory management and ownership models
- Iterator design and traversal semantics
- Container API design and modular implementation (`.hpp`/`.tpp` split)
- Fundamental algorithm implementation and complexity awareness

## Implemented Components

### Containers

- `rub::vector` (dynamic array)
- `rub::list` (doubly linked list)
- `rub::stack` (list-based)
- `rub::queue` (list-based)
- `rub::set` (BST-backed ordered unique container)

### Iterators

- `rub::forward_iterator`
- `rub::random_access_iterator`
- List iterators (`list_iterator`)
- Reverse iterator support where applicable via `std::reverse_iterator`

### Smart Pointers

- `rub::unique_ptr` (+ array specialization)
- `rub::shared_ptr` (+ array specialization)
  - Atomic reference counting via control blocks
  - Custom deleter support
  - Conversions from `unique_ptr` where supported

### Algorithms and Utilities

- Sorting algorithms: bubble sort, merge sort, quick sort
- Generic utility helpers in `algorithms/tools.*`
- Custom exception type: `rub::exception`
- Custom pair utility: `rub::pair`

## Project Structure

```text
algorithms/
containers/
  list/
  queue/
  set/
  stack/
  vector/
exception/
iterator/
  forward_iterator/
  random_access_iterator/
pair/
smart_pointers/
  shared_ptr/
  unique_ptr/
```

## Build and Run (Example)

A simple vector demo is provided in `containers/vector/main.cpp`.

```bash
g++ -std=c++17 -Wall -Wextra -Werror containers/vector/main.cpp -o vector_demo
./vector_demo
```

## Design Notes

- Most modules are split into declarations (`.h`/`.hpp`) and template implementations (`.tpp`).
- The code is organized for learning and clarity, with each data structure implemented as an independent component.
- APIs are intentionally STL-inspired to practice real-world C++ interface design.

## Learning Outcomes

This codebase demonstrates practical understanding of:

- Value vs. reference semantics
- Move semantics and resource transfer
- Ownership and lifetime management
- Iterator contracts and traversal behavior
- Tree and hash-based lookup strategies
- Building reusable generic libraries in modern C++
