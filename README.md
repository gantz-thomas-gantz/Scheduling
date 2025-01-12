# Task Scheduling Project

This project implements an efficient task scheduling system using different algorithms to calculate the end time of tasks in a Directed Acyclic Graph (DAG). It also includes testing for correctness and performance evaluation using different configurations.

## Features

- **Topological Sort**: Schedules tasks in a valid order respecting their dependencies.
- **Shortest Job First (SJF)**: A variation of topological sort where tasks with the shortest durations are prioritized.
- **Limited Workers Scheduling**: Schedules tasks with a constrained number of available workers.
- **Unlimited Workers Scheduling**: Schedules tasks assuming an unlimited number of workers.
- **Performance Testing**: Supports performance tests for various task sizes (N) and configurations.

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
├── CMakeLists.txt
├── README.md
├── results.txt
├── times.txt
└── report.pdf
```

## Data Structures

### 1. **Graph Structure**

A directed acyclic graph (DAG) is used to represent the tasks and their dependencies. Each task in the graph contains information about its duration, its prerequisites, and its successors.

- **Task struct**:
  - `duration`: Execution time of the task.
  - `end`: The calculated end time for the task.
  - `req`: The number of prerequisite tasks.
  - `ns`: The number of successor tasks.
  - `successors`: Array of indices indicating successor tasks.

### 2. **Heap**

A min-heap data structure is used to handle tasks with the shortest duration or shortest end time first. This is useful in the **Shortest Job First (SJF)**, **Limited Workers** and **Unlimited Workers** scheduling algorithms.

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

## Scheduling Algorithms

### 1. **Topological Sort**
- Processes tasks in order respecting their dependencies, with tasks that have no prerequisites scheduled first.

### 2. **Shortest Job First (SJF)**
- A variant of topological sort where tasks with shorter durations are prioritized.

### 3. **Limited Workers Scheduling**
- Assigns tasks to a fixed number of workers, scheduling tasks based on their readiness and duration.

### 4. **Unlimited Workers Scheduling**
- Assigns tasks without limitation on the number of workers, processing all ready tasks in parallel.

## Testing and Performance Evaluation

### 1. **Test Correctness**
- Verifies that tasks' end times respect the dependencies and do not overlap in an incorrect order.

### 2. **Performance Test**
- Measures the execution time and efficiency of different scheduling algorithms.

## How to Compile and Run

```bash
cmake -B build
cmake --build build
build/main
```

This will create two files:
- `results.txt`: Contains the total execution times of the different schedules.
- `times.txt`: Contains the execution times of the scheduling algorithms.




