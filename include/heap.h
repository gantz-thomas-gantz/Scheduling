#ifndef HEAP_H
#define HEAP_H

// Definition of a heap node
// Each node contains an index and a value used for ordering in the heap
typedef struct {
    int i;         // Integer identifier (task index)
    double val;    // Value used for heap ordering (task duration or priority)
} heap_node;

// Definition of the min-heap
// A min-heap is a binary tree where the parent node's value is always smaller than the child nodes
typedef struct {
    heap_node* data; // Dynamic array storing heap nodes
    int size;        // Current number of elements in the heap
    int capacity;    // Maximum capacity of the heap
} min_heap;

/**
 * @brief Creates a min heap with an initial capacity.
 * 
 * @param initial_capacity The initial capacity of the heap.
 * @return A pointer to the created min heap.
 */
min_heap* create_min_heap(int initial_capacity);

/**
 * @brief Frees the memory allocated for the min heap.
 * 
 * @param heap Pointer to the min heap to be freed.
 */
void free_min_heap(min_heap* heap);

/**
 * @brief Inserts a new node into the min heap.
 * 
 * @param heap Pointer to the min heap.
 * @param i The index associated with the node.
 * @param val The value of the node to be inserted.
 */
void insert(min_heap* heap, int i, double val);

/**
 * @brief Extracts and removes the minimum node from the heap.
 * 
 * @param heap Pointer to the min heap.
 * @return The minimum node (heap_node).
 */
heap_node extract_min(min_heap* heap);

#endif /* HEAP_H */



