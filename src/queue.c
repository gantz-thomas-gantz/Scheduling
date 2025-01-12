#include <stdio.h>
#include <stdlib.h>

#include "../include/queue.h"

/**
 * @brief Initializes a circular queue with the specified initial capacity.
 * 
 * @param q Pointer to the circular queue to be initialized.
 * @param initial_capacity The initial capacity of the queue.
 */
void init_circular_queue(CircularQueue *q, int initial_capacity) {
    q->capacity = initial_capacity;
    q->front = q->rear = 0;
    q->data = (int *)malloc(q->capacity * sizeof(int));
}

/**
 * @brief Checks whether the circular queue is empty.
 * 
 * @param q Pointer to the circular queue.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int is_empty(CircularQueue *q) {
    return q->front == q->rear;
}

/**
 * @brief Checks whether the circular queue is full.
 * 
 * @param q Pointer to the circular queue.
 * @return 1 if the queue is full, 0 otherwise.
 */
int is_full(CircularQueue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

/**
 * @brief Resizes the circular queue when it is full by doubling its capacity.
 * 
 * @param q Pointer to the circular queue to be resized.
 */
static void resize_queue(CircularQueue *q) {
    int new_capacity = q->capacity * 2;
    int *new_data = (int *)malloc(new_capacity * sizeof(int));

    // Calculate current size based on front and rear positions
    int current_size = (q->rear - q->front + q->capacity) % q->capacity;

    // Copy elements to the new array, maintaining order
    for (int i = 0; i < current_size; i++) {
        new_data[i] = q->data[(q->front + i) % q->capacity];
    }

    free(q->data);
    q->data = new_data;
    q->front = 0;
    q->rear = current_size;
    q->capacity = new_capacity;
}

/**
 * @brief Adds an element to the circular queue.
 * 
 * @param q Pointer to the circular queue.
 * @param item The item to be added to the queue.
 */
void enqueue(CircularQueue *q, int item) {
    if (is_full(q)) {
        resize_queue(q);  // Resize if the queue is full
    }
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % q->capacity;
}

/**
 * @brief Removes and returns an element from the circular queue.
 * 
 * @param q Pointer to the circular queue.
 * @return The item removed from the queue. Returns -1 if the queue is empty.
 */
int dequeue(CircularQueue *q) {
    if (is_empty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return item;
}

/**
 * @brief Frees the memory allocated for the circular queue.
 * 
 * @param q Pointer to the circular queue to be freed.
 */
void free_circular_queue(CircularQueue *q) {
    free(q->data);
}



