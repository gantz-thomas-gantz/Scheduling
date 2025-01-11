#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include "../include/graph.h"

void topological_sort(struct Task *dag, int N);
void topological_sort_SJF(struct Task *dag, int N);

#endif /* TOPOLOGICAL_SORT_H */

