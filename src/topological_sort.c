#include <stdio.h>
#include <stdlib.h>

#include "../include/topological_sort.h"
#include "../include/graph.h"
#include "../include/queue.h"
#include "../include/heap.h"

// DFS complicated with this encoding
// BFS (Kahn's algorithm): why queue if I can directly use a heap (SJF)?

#define SHIFT 10e-10

void topological_sort(struct Task *dag, int N) {
    set_req(dag, N);
    CircularQueue q;
    init_circular_queue(&q, N);  // Initialize the circular queue with a capacity of N tasks

    double TIME = 0.;

    // Enqueue tasks with no prerequisites (req == 0)
    for (int i = 0; i < N; i++) {
        if (dag[i].req == 0) {
            enqueue(&q, i);
        }
    }

    while (!is_empty(&q)) {
        int task_idx = dequeue(&q);  // Dequeue the task
        dag[task_idx].end = TIME + dag[task_idx].duration + SHIFT;
        TIME += dag[task_idx].duration + SHIFT;  // Update the current time with the task duration

        // Process the successors of the current task
        for (int k = 0; k < dag[task_idx].ns; k++) {
            int successor_idx = dag[task_idx].successors[k];
            dag[successor_idx].req--;  // Decrease the prerequisite count
            if (dag[successor_idx].req == 0) {
                enqueue(&q, successor_idx);  // Enqueue if there are no more prerequisites
            }
        }
    }

    free_circular_queue(&q);  // Free the allocated memory for the circular queue
}

void topological_sort_SJF(struct Task *dag, int N){
    set_req(dag,N);
    min_heap *heap = create_min_heap(N/100+10); // randomly chosen
    double TIME = 0.;

    for(int i=0; i<N; i++){
        if(dag[i].req==0){
            insert(heap,i,dag[i].duration);
        } 
    }

    while(heap->size>0){
        heap_node node = extract_min(heap);
        int task_idx = node.i;
        dag[task_idx].end = TIME + node.val;
        TIME += node.val + SHIFT;
        for(int k=0; k<dag[task_idx].ns; k++){
            int successor_idx = dag[task_idx].successors[k];
            dag[successor_idx].req--;
            if(dag[successor_idx].req==0){
                insert(heap, successor_idx, dag[successor_idx].duration);
            } 
        }
    }
    free_min_heap(heap);
}







