#include <stdlib.h>
#include <stdio.h>

#include "../include/heap.h"

/**
 * @brief Creates a min heap with an initial capacity.
 * 
 * @param initial_capacity The initial capacity of the heap.
 * @return A pointer to the created min heap.
 */
min_heap* create_min_heap(int initial_capacity) {
    // Allocate memory for the heap structure
    min_heap* heap = (min_heap*)malloc(sizeof(min_heap));
    if (!heap) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the dynamic array
    heap->data = (heap_node*)malloc(initial_capacity * sizeof(heap_node));
    if (!heap->data) {
        fprintf(stderr, "Memory allocation failed\n");
        free(heap);
        exit(EXIT_FAILURE);
    }

    heap->size = 0;
    heap->capacity = initial_capacity;
    return heap;
}

/**
 * @brief Frees the memory allocated for the min heap.
 * 
 * @param heap Pointer to the min heap to be freed.
 */
void free_min_heap(min_heap* heap) {
    // Free the dynamic array and heap structure
    free(heap->data);
    free(heap);
}

/**
 * @brief Returns the index of the parent of the given index.
 * 
 * @param index The index of the node.
 * @return The index of the parent node.
 */
static int parent(int index) {
    return (index - 1) / 2;
}

/**
 * @brief Returns the index of the left child of the given index.
 * 
 * @param index The index of the node.
 * @return The index of the left child.
 */
static int left_child(int index) {
    return 2 * index + 1;
}

/**
 * @brief Returns the index of the right child of the given index.
 * 
 * @param index The index of the node.
 * @return The index of the right child.
 */
static int right_child(int index) {
    return 2 * index + 2;
}

/**
 * @brief Swaps two heap nodes.
 * 
 * @param a Pointer to the first heap node.
 * @param b Pointer to the second heap node.
 */
static void swap(heap_node* a, heap_node* b) {
    heap_node temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Resizes the heap when it reaches its capacity, doubling the size.
 * 
 * @param heap Pointer to the min heap to be resized.
 */
static void resize_heap(min_heap* heap) {
    // Double the capacity of the heap
    int new_capacity = heap->capacity * 2;
    heap_node* new_data = (heap_node*)realloc(heap->data, new_capacity * sizeof(heap_node));
    if (!new_data) {
        fprintf(stderr, "Memory allocation failed during resize\n");
        exit(EXIT_FAILURE);
    }

    heap->data = new_data;
    heap->capacity = new_capacity;
}

/**
 * @brief Restores the heap property by moving a node upwards in the heap.
 * 
 * @param heap Pointer to the min heap.
 * @param index The index of the node to be sifted up.
 */
static void sift_up(min_heap* heap, int index) {
    while (index > 0 && heap->data[parent(index)].val > heap->data[index].val) {
        swap(&heap->data[parent(index)], &heap->data[index]);
        index = parent(index);
    }
}

/**
 * @brief Inserts a new node into the min heap.
 * 
 * @param heap Pointer to the min heap.
 * @param i The index associated with the node.
 * @param val The value of the node to be inserted.
 */
void insert(min_heap* heap, int i, double val) {
    // Resize if the heap is full
    if (heap->size == heap->capacity) {
        resize_heap(heap);
    }

    // Add the new node at the end of the heap
    heap->data[heap->size].i = i;
    heap->data[heap->size].val = val;
    heap->size++;

    // Restore heap property by sifting up
    sift_up(heap, heap->size - 1);
}

/**
 * @brief Restores the heap property by moving a node downwards in the heap.
 * 
 * @param heap Pointer to the min heap.
 * @param index The index of the node to be sifted down.
 */
static void sift_down(min_heap* heap, int index) {
    int smallest = index;
    int left = left_child(index);
    int right = right_child(index);

    if (left < heap->size && heap->data[left].val < heap->data[smallest].val) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right].val < heap->data[smallest].val) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        sift_down(heap, smallest);
    }
}

/**
 * @brief Extracts and removes the minimum node from the heap.
 * 
 * @param heap Pointer to the min heap.
 * @return The minimum node (heap_node).
 */
heap_node extract_min(min_heap* heap) {
    if (heap->size == 0) {
        fprintf(stderr, "Heap is empty\n");
        exit(EXIT_FAILURE);
    }

    // Store the minimum node
    heap_node min_node = heap->data[0];

    // Replace the root with the last element
    heap->data[0] = heap->data[--heap->size];

    // Restore heap property by sifting down
    sift_down(heap, 0);

    return min_node;
}


