Sure! Here's a `README.md` that covers the entire project, including a brief description of each component.

```markdown
# Task Scheduling Project

This project implements an efficient task scheduling system using different algorithms to calculate the end time of tasks in a Directed Acyclic Graph (DAG). The system is based on two main scheduling strategies: **Topological Sort** and **Shortest Job First (SJF)**. It also includes testing for correctness and performance evaluation using different worker configurations.

## Features

- **Topological Sort**: Schedules tasks in a valid order respecting their dependencies.
- **Shortest Job First (SJF)**: A variation of topological sort where tasks with the shortest durations are prioritized.
- **Limited Workers Scheduling**: Schedules tasks with a constrained number of available workers.
- **Unlimited Workers Scheduling**: Schedules tasks assuming an unlimited number of workers.
- **Performance Testing**: Supports performance tests for various task sizes (N) and configurations (number of workers).

## Directory Structure

```
├── include/
│   ├── graph.h
│   ├── heap.h
│   ├── queue.h
│   ├── scheduling.h
│   ├── test.h
│   └── topological_sort.h
├── src/
│   ├── graph.c
│   ├── heap.c
│   ├── queue.c
│   ├── scheduling.c
│   ├── test.c
│   ├── topological_sort.c
│   └── main.c
├── Makefile
└── README.md
```

## Key Components

### 1. **Graph Structure**

A directed acyclic graph (DAG) is used to represent the tasks and their dependencies. Each task in the graph contains information about its duration, its prerequisites, and its successors.

- **Task struct**:
  - `duration`: Execution time of the task.
  - `end`: The calculated end time for the task.
  - `req`: The number of prerequisite tasks.
  - `ns`: The number of successor tasks.
  - `successors`: Array of indices pointing to successor tasks.

### 2. **Heap**

A min-heap data structure is used to handle tasks with the shortest duration first. This is useful in the **Shortest Job First (SJF)** and **Limited Workers** scheduling algorithms.

- **min_heap struct**:
  - `data`: Array storing heap nodes (tasks).
  - `size`: Current size of the heap.
  - `capacity`: Maximum capacity of the heap.

### 3. **Circular Queue**

A circular queue is used in the **Topological Sort** to manage tasks that are ready to be scheduled (i.e., tasks with no prerequisites).

- **CircularQueue struct**:
  - `data`: Array storing the elements.
  - `front`: Index of the front element.
  - `rear`: Index of the rear element.
  - `capacity`: Maximum capacity of the queue.

### 4. **Scheduling Algorithms**

- **Topological Sort**: 
  - Processes tasks in order respecting their dependencies, with tasks that have no prerequisites scheduled first.
- **Shortest Job First (SJF)**:
  - A variant of topological sort where tasks with shorter durations are prioritized.

### 5. **Worker Scheduling**

- **Limited Workers**: 
  - Assigns tasks to a fixed number of workers, scheduling tasks based on their readiness and duration.
- **Unlimited Workers**:
  - Assigns tasks without limitation on the number of workers, processing all ready tasks in parallel.

### 6. **Testing and Performance Evaluation**

- **Test Correctness**: Verifies that tasks' end times respect the dependencies and do not overlap in an incorrect order.
- **Performance Test**: 
  - Measures the execution time and efficiency of different scheduling strategies across a range of task sizes.

## How to Compile and Run

```bash
cmake -B build
cmake --build build
build/main
```

This will create two files:
- `results.txt`: Contains the total execution times of the different schedules.
- `times.txt`: Contains the execution times of the scheduling algorithms.


