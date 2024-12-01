#include "../include/heap.h"

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

void free_min_heap(min_heap* heap) {
    // Free the dynamic array and heap structure
    free(heap->data);
    free(heap);
}

static int parent(int index) {
    return (index - 1) / 2;
}

static int left_child(int index) {
    return 2 * index + 1;
}

static int right_child(int index) {
    return 2 * index + 2;
}

static void swap(heap_node* a, heap_node* b) {
    heap_node temp = *a;
    *a = *b;
    *b = temp;
}

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

static void sift_up(min_heap* heap, int index) {
    while (index > 0 && heap->data[parent(index)].val > heap->data[index].val) {
        swap(&heap->data[parent(index)], &heap->data[index]);
        index = parent(index);
    }
}

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


