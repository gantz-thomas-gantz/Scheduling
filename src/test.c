#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>

#include "../include/test.h"
#include "../include/graph.h"
#include "../include/scheduling.h"

// call successors correctly !!!
static bool test_correctness(struct Task *dag, int N){
    for(int task_idx=0; task_idx<N; task_idx++){
        double predecessor_end = dag[task_idx].end;
        for(int successor_idx=0; successor_idx<dag[task_idx].ns; successor_idx++){
            double succesor_start = dag[successor_idx].end - dag[successor_idx].duration;
            if(succesor_start<predecessor_end){
                return false;
            } 
        }
    }
    return true;
}

double TEST_schedule_end_unlimited_workers(int N){
    struct Task *dag = malloc(N*sizeof(struct Task));
    generate_random_DAG(dag,N);
    schedule_end_unlimited_workers(dag,N);
    if(test_correctness(dag,N)==false) return -1.0;
    double end = 0.0;
    for(int task_idx=0; task_idx<N; task_idx++){
        printf("%lf\n", dag[task_idx].end);
        end = end >= dag[task_idx].end ? end : dag[task_idx].end;
    }
    free_random_DAG(dag,N);
    return end;
}

double TEST_schedule_end_limited_workers(int N, int workers){
    struct Task *dag = malloc(N*sizeof(struct Task));
    generate_random_DAG(dag,N);
    schedule_end_limited_workers(dag,N,workers);
    if(test_correctness(dag,N)==false) return -1.0;
    double end = 0.0;
    for(int task_idx=0; task_idx<N; task_idx++){
        end = end >= dag[task_idx].end ? end : dag[task_idx].end;
    }
    free_random_DAG(dag,N);
    return end;
}