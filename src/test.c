#include <stdlib.h>
#include <stdbool.h>

#include "../include/test.h"
#include "../include/graph.h"
#include "../include/scheduling.h"
#include "../include/topological_sort.h"

/**
 * @brief Validates the correctness of the task DAG by ensuring that all successor tasks
 * start after their respective predecessors finish.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @return true if the DAG is correct, false otherwise.
 */
static bool test_correctness(struct Task *dag, int N){
    for(int task_idx=0; task_idx<N; task_idx++){
        double predecessor_end = dag[task_idx].end;
        for(int k=0; k<dag[task_idx].ns; k++){
            int successor_idx = dag[task_idx].successors[k];
            double successor_start = dag[successor_idx].end - dag[successor_idx].duration;
            if(successor_start <= predecessor_end){
                return false;
            } 
        }
    }
    return true;
}

/**
 * @brief Tests the topological sort and returns the completion time of the last task.
 * Validates correctness by checking the DAG, and returns -1 if the DAG is invalid.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @return The total completion time if the DAG is valid, -1 otherwise.
 */
double TEST_topological_sort(struct Task *dag, int N){
    topological_sort(dag, N);
    if(test_correctness(dag, N) == false) return -1.0;
    double end = 0.0;
    for(int task_idx=0; task_idx<N; task_idx++){
        end = end >= dag[task_idx].end ? end : dag[task_idx].end;
    }
    return end;
}

/**
 * @brief Tests the Shortest-Job-First (SJF) topological sort and returns the completion time of the last task.
 * Validates correctness by checking the DAG, and returns -1 if the DAG is invalid.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @return The total completion time if the DAG is valid, -1 otherwise.
 */
double TEST_topological_sort_SJF(struct Task *dag, int N){
    topological_sort_SJF(dag, N);
    if(test_correctness(dag, N) == false) return -1.0;
    double end = 0.0;
    for(int task_idx=0; task_idx<N; task_idx++){
        end = end >= dag[task_idx].end ? end : dag[task_idx].end;
    }
    return end;
}

/**
 * @brief Tests the scheduling with unlimited workers and returns the completion time of the last task.
 * Validates correctness by checking the DAG, and returns -1 if the DAG is invalid.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @return The total completion time if the DAG is valid, -1 otherwise.
 */
double TEST_unlimited_workers(struct Task *dag, int N){
    unlimited_workers(dag, N);
    if(test_correctness(dag, N) == false) return -1.0;
    double end = 0.0;
    for(int task_idx=0; task_idx<N; task_idx++){
        end = end >= dag[task_idx].end ? end : dag[task_idx].end;
    }
    return end;
}

/**
 * @brief Tests the scheduling with a limited number of workers and returns the completion time of the last task.
 * Validates correctness by checking the DAG, and returns -1 if the DAG is invalid.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @param workers The maximum number of workers that can work simultaneously.
 * @return The total completion time if the DAG is valid, -1 otherwise.
 */
double TEST_limited_workers(struct Task *dag, int N, int workers){
    limited_workers(dag, N, workers);
    if(test_correctness(dag, N) == false) return -1.0;
    double end = 0.0;
    for(int task_idx=0; task_idx<N; task_idx++){
        end = end >= dag[task_idx].end ? end : dag[task_idx].end;
    }
    return end;
}
