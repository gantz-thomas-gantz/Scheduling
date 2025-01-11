#ifndef TEST_H
#define TEST_H

#include "../include/graph.h"

double TEST_topological_sort(struct Task *dag, int N);
double TEST_unlimited_workers(struct Task *dag, int N);
double TEST_limited_workers(struct Task *dag, int N, int workers);

#endif /* TEST_H */