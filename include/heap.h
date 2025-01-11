#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

// Definition of a heap node
typedef struct {
    int i;         // Integer identifier (task index)
    double val;    // Value used for heap ordering (task duration)
} heap_node;

// Definition of the min-heap
typedef struct {
    heap_node* data; // Dynamic array storing heap nodes
    int size;        // Current number of elements
    int capacity;    // Maximum capacity of the heap
} min_heap;

min_heap* create_min_heap(int initial_capacity);
void free_min_heap(min_heap* heap);
void insert(min_heap* heap, int i, double val);
heap_node extract_min(min_heap* heap);

#endif /* HEAP_H */


