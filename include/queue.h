#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} CircularQueue;

void init_circular_queue(CircularQueue *q, int initial_capacity); 
int is_empty(CircularQueue *q); 
int is_full(CircularQueue *q);  
void enqueue(CircularQueue *q, int item); 
int dequeue(CircularQueue *q);
void free_circular_queue(CircularQueue *q);


