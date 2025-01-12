#include "../include/scheduling.h"
#include "../include/graph.h"
#include "../include/heap.h"

#define SHIFT 10e-10 // Small value to ensure numerical correctness.

/**
 * @brief Function to handle scheduling with unlimited workers.
 * Tasks are processed as soon as they are ready.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 */
void unlimited_workers(struct Task *dag, int N) {
    set_req(dag, N);  // Set the number of prerequisites for each task
    
    min_heap *heap = create_min_heap(N / 100 + 10); // Create heap to store tasks that can be processed
    
    // Add all tasks with no prerequisites to the heap
    for (int i = 0; i < N; i++) {
        if (dag[i].req == 0) {
            insert(heap, i, dag[i].duration);
        }
    }

    // Process tasks in the heap
    while (heap->size > 0) {
        heap_node node = extract_min(heap);  // Extract the task with the shortest duration
        int task_idx = node.i;
        dag[task_idx].end = node.val;  // Update the task's end time

        // Process the successors of the completed task
        for (int k = 0; k < dag[task_idx].ns; k++) {
            int successor_idx = dag[task_idx].successors[k];
            dag[successor_idx].req--;
            
            // If all prerequisites are completed, add to heap
            if (dag[successor_idx].req == 0) {
                insert(heap, successor_idx, dag[task_idx].end + dag[successor_idx].duration + SHIFT);
            }
        }
    }

    free_min_heap(heap);  // Free the heap memory
}

/**
 * @brief Function to handle scheduling with a limited number of workers.
 * The number of active workers is restricted, and tasks are scheduled as soon as workers are available.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @param workers The maximum number of workers that can work simultaneously.
 */
void limited_workers(struct Task *dag, int N, int workers) {
    set_req(dag, N);  // Set the number of prerequisites for each task
    
    min_heap *startable = create_min_heap(N / 100 + 10); // Heap for tasks that can start
    min_heap *started = create_min_heap(N / 100 + 10);  // Heap for tasks that are being processed

    int active_workers = 0;  // Number of active workers

    // Add all tasks with no prerequisites to the startable heap
    for (int i = 0; i < N; i++) {
        if (dag[i].req == 0) {
            insert(startable, i, dag[i].duration);
        }
    }

    // Start as many tasks as there are available workers
    while (startable->size > 0 && active_workers < workers) {
        heap_node startable_node = extract_min(startable);  // Extract the task with the shortest duration
        insert(started, startable_node.i, dag[startable_node.i].duration);  // Insert into started heap
        active_workers++;  // Increase the active worker count
    }

    // Process tasks in the started heap
    while (started->size > 0) {
        heap_node started_node = extract_min(started);  // Extract the task that finished execution
        active_workers--;  // Decrease active worker count
        int task_idx = started_node.i;
        dag[task_idx].end = started_node.val;  // Update the task's end time

        // Process the successors of the completed task
        for (int k = 0; k < dag[task_idx].ns; k++) {
            int successor_idx = dag[task_idx].successors[k];
            dag[successor_idx].req--;
            
            // If all prerequisites are completed, add to startable heap
            if (dag[successor_idx].req == 0) {
                insert(startable, successor_idx, dag[successor_idx].duration);
            }
        }

        // Start as many tasks as possible, respecting the worker limit
        while (startable->size > 0 && active_workers < workers) {
            heap_node startable_node = extract_min(startable);  // Extract the next ready task
            insert(started, startable_node.i, dag[task_idx].end + dag[startable_node.i].duration + SHIFT);
            active_workers++;  // Increase the active worker count
        }
    }

    free_min_heap(startable);  // Free memory for the startable heap
    free_min_heap(started);  // Free memory for the started heap
}




