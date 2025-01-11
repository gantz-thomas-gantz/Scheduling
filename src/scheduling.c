#include "../include/scheduling.h"
#include "../include/graph.h"
#include "../include/heap.h"

#define SHIFT 10e-10

// insert = launch
// extract = finished

// O(V * logV + E) E = V^2/2

void unlimited_workers(struct Task *dag, int N){
    set_req(dag,N);
    min_heap *heap = create_min_heap(N/100+10); // randomly chosen
    for(int i=0; i<N; i++){
        if(dag[i].req==0){
            insert(heap,i,dag[i].duration);
        } 
    }
    while(heap->size>0){
        heap_node node = extract_min(heap);
        int task_idx = node.i;
        dag[task_idx].end = node.val;
        for(int k=0; k<dag[task_idx].ns; k++){
            int successor_idx = dag[task_idx].successors[k];
            dag[successor_idx].req--;
            if(dag[successor_idx].req==0){
                insert(heap, successor_idx, dag[task_idx].end + dag[successor_idx].duration + SHIFT);
            } 
        }
    }
    free_min_heap(heap);
}

// Shortest-Job-First in startable
// Alternative: Job with the most successors first

void limited_workers(struct Task *dag, int N, int workers){
    set_req(dag,N);
    min_heap *startable = create_min_heap(N/100+10); // randomly chosen
    min_heap *started = create_min_heap(N/100+10); // randomly chosen

    int active_workers = 0;
    
    for(int i=0; i<N; i++){
        if(dag[i].req==0){
            insert(startable,i,dag[i].duration);
        } 
    }

    while(startable->size>0 && active_workers<workers){
        heap_node startable_node = extract_min(startable);
        insert(started, startable_node.i, dag[startable_node.i].duration);
        active_workers++;
    }

    while(started->size>0){

        heap_node started_node = extract_min(started);
        active_workers--;
        int task_idx = started_node.i;
        dag[task_idx].end = started_node.val;
        
        for(int k=0; k<dag[task_idx].ns; k++){
            int successor_idx = dag[task_idx].successors[k];
            dag[successor_idx].req--;
            if(dag[successor_idx].req==0){
                insert(startable, successor_idx, dag[successor_idx].duration); 
            } 
        }

        while(startable->size>0 && active_workers<workers){
            heap_node startable_node = extract_min(startable);
            insert(started, startable_node.i, dag[task_idx].end + dag[startable_node.i].duration + SHIFT);
            active_workers++;
        }
    }
    free_min_heap(startable);
    free_min_heap(started);
}


