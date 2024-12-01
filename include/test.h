#ifndef TEST_H
#define TEST_H

#include "../include/graph.h"

double TEST_schedule_end_unlimited_workers(int N);
double TEST_schedule_end_limited_workers(int N, int workers);

#endif /* TEST_H */