#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

// Definition des Objekts
typedef struct {
    int i;         // Integer identifier
    double val;    // Value used for heap ordering
} heap_node;

// Definition des Min-Heaps
typedef struct {
    heap_node* data; // Dynamic array to store heap nodes
    int size;        // Current number of elements
    int capacity;    // Maximum capacity of the heap
} min_heap;

// Prototypes
min_heap* create_min_heap(int initial_capacity);
void free_min_heap(min_heap* heap);
void insert(min_heap* heap, int i, double val);
heap_node extract_min(min_heap* heap);

#endif /* HEAP_H */


