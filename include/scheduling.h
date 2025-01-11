#ifndef SCHEDULING_H
#define SCHEDULING_H

#include "../include/graph.h"

void unlimited_workers(struct Task *dag, int N);
void limited_workers(struct Task *dag, int N, int workers);

#endif /* SCHEDULING_H */