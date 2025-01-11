#include <stdio.h>
#include <stdlib.h>

#include "../include/topological_sort.h"
#include "../include/graph.h"
#include "../include/heap.h"

// DFS complicated with this encoding
// BFS (Kahn's algorithm): why queue if I can directly use a heap (SJF)?

#define SHIFT 10e-10

void topological_sort(struct Task *dag, int N){
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




