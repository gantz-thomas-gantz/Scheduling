#ifndef TEST_H
#define TEST_H

#include "../include/graph.h"

double TEST_schedule_end_unlimited_workers(struct Task *dag, int N);
double TEST_schedule_end_limited_workers(struct Task *dag, int N, int workers);

#endif /* TEST_H */