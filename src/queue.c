#include <stdio.h>
#include <stdlib.h>

#include "../include/queue.h"

void init_circular_queue(CircularQueue *q, int initial_capacity) {
    q->capacity = initial_capacity;
    q->front = q->rear = 0;
    q->data = (int *)malloc(q->capacity * sizeof(int));
}

int is_empty(CircularQueue *q) {
    return q->front == q->rear;
}

int is_full(CircularQueue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

static void resize_queue(CircularQueue *q) {
    int new_capacity = q->capacity * 2;
    int *new_data = (int *)malloc(new_capacity * sizeof(int));

    int current_size = (q->rear - q->front + q->capacity) % q->capacity;

    // Copy elements to the new array
    for (int i = 0; i < current_size; i++) {
        new_data[i] = q->data[(q->front + i) % q->capacity];
    }

    free(q->data);
    q->data = new_data;
    q->front = 0;
    q->rear = current_size;
    q->capacity = new_capacity;
}

void enqueue(CircularQueue *q, int item) {
    if (is_full(q)) {
        resize_queue(q);  // Resize if the queue is full
    }
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % q->capacity;
}

int dequeue(CircularQueue *q) {
    if (is_empty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return item;
}

void free_circular_queue(CircularQueue *q) {
    free(q->data);
}


