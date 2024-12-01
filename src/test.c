#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>

#include "../include/test.h"
#include "../include/graph.h"
#include "../include/scheduling.h"

static bool test_correctness(struct Task *dag, int N){
    for(int task_idx=0; task_idx<N; task_idx++){
        double predecessor_end = dag[task_idx].end;
        for(int k=0; k<dag[task_idx].ns; k++){
            int successor_idx = dag[task_idx].successors[k];
            double successor_start = dag[successor_idx].end - dag[successor_idx].duration;
            if(successor_start<=predecessor_end){
                return false;
            } 
        }
    }
    return true;
}

double TEST_schedule_end_unlimited_workers(struct Task *dag, int N){
    schedule_end_unlimited_workers(dag,N);
    if(test_correctness(dag,N)==false) return -1.0;
    double end = 0.0;
    for(int task_idx=0; task_idx<N; task_idx++){
        end = end >= dag[task_idx].end ? end : dag[task_idx].end;
    }
    return end;
}

double TEST_schedule_end_limited_workers(struct Task *dag, int N, int workers){
    schedule_end_limited_workers(dag,N,workers);
    if(test_correctness(dag,N)==false) return -1.0;
    double end = 0.0;
    for(int task_idx=0; task_idx<N; task_idx++){
        end = end >= dag[task_idx].end ? end : dag[task_idx].end;
    }
    return end;
}