#ifndef SCHEDULING_H
#define SCHEDULING_H

#include "../include/graph.h"

/**
 * Function to handle scheduling with unlimited workers.
 * Tasks are processed as soon as they are ready, and their successors are scheduled once completed.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 */
void unlimited_workers(struct Task *dag, int N);

/**
 * Function to handle scheduling with a limited number of workers.
 * The number of active workers is restricted, and tasks are scheduled as soon as workers are available.
 * 
 * @param dag The directed acyclic graph representing tasks and their dependencies.
 * @param N The number of tasks in the graph.
 * @param workers The maximum number of workers that can work simultaneously.
 */
void limited_workers(struct Task *dag, int N, int workers);

#endif /* SCHEDULING_H */
