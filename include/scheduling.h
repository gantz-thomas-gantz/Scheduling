#ifndef SCHEDULING_H
#define SCHEDULING_H

#include "../include/graph.h"

void schedule_end_unlimited_workers(struct Task *dag, int N);
void schedule_end_limited_workers(struct Task *dag, int N, int workers);

#endif /* SCHEDULING_H */