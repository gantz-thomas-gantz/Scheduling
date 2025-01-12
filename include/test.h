#ifndef TEST_H
#define TEST_H

#include "../include/graph.h"

/**
 * @brief Tests the topological sort and returns the completion time of the last task.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @return The total completion time if the DAG is valid, -1 otherwise.
 */
double TEST_topological_sort(struct Task *dag, int N);

/**
 * @brief Tests the Shortest-Job-First (SJF) topological sort and returns the completion time of the last task.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @return The total completion time if the DAG is valid, -1 otherwise.
 */
double TEST_topological_sort_SJF(struct Task *dag, int N);

/**
 * @brief Tests the scheduling with unlimited workers and returns the completion time of the last task.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @return The total completion time if the DAG is valid, -1 otherwise.
 */
double TEST_unlimited_workers(struct Task *dag, int N);

/**
 * @brief Tests the scheduling with a limited number of workers and returns the completion time of the last task.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @param workers The maximum number of workers that can work simultaneously.
 * @return The total completion time if the DAG is valid, -1 otherwise.
 */
double TEST_limited_workers(struct Task *dag, int N, int workers);

#endif /* TEST_H */
