#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include "../include/graph.h"

/**
 * @brief Performs a topological sort on the task graph and calculates the end time of each task.
 * 
 * This function processes tasks in a directed acyclic graph (DAG) in topological order, 
 * starting from tasks with no prerequisites and updating their end times based on task durations.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 */
void topological_sort(struct Task *dag, int N);

/**
 * @brief Performs a Shortest-Job-First (SJF) topological sort on the task graph and calculates the end time of each task.
 * 
 * This function processes tasks in a directed acyclic graph (DAG) in topological order, 
 * prioritizing the shortest tasks first to minimize total completion time.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 */
void topological_sort_SJF(struct Task *dag, int N);

#endif /* TOPOLOGICAL_SORT_H */


