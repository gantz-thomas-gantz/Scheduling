#ifndef QUEUE_H
#define QUEUE_H

// Definition of the CircularQueue structure
typedef struct {
    int *data;      // Array to hold the queue elements
    int front;      // Index of the front element in the queue
    int rear;       // Index of the rear element in the queue
    int capacity;   // Maximum capacity of the queue
} CircularQueue;

/**
 * @brief Initializes a circular queue with the specified initial capacity.
 * 
 * @param q Pointer to the circular queue to be initialized.
 * @param initial_capacity The initial capacity of the queue.
 */
void init_circular_queue(CircularQueue *q, int initial_capacity); 

/**
 * @brief Checks whether the circular queue is empty.
 * 
 * @param q Pointer to the circular queue.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int is_empty(CircularQueue *q); 

/**
 * @brief Checks whether the circular queue is full.
 * 
 * @param q Pointer to the circular queue.
 * @return 1 if the queue is full, 0 otherwise.
 */
int is_full(CircularQueue *q);  

/**
 * @brief Adds an element to the circular queue.
 * 
 * @param q Pointer to the circular queue.
 * @param item The item to be added to the queue.
 */
void enqueue(CircularQueue *q, int item); 

/**
 * @brief Removes and returns an element from the circular queue.
 * 
 * @param q Pointer to the circular queue.
 * @return The item removed from the queue. Returns -1 if the queue is empty.
 */
int dequeue(CircularQueue *q);

/**
 * @brief Frees the memory allocated for the circular queue.
 * 
 * @param q Pointer to the circular queue to be freed.
 */
void free_circular_queue(CircularQueue *q);

#endif /* QUEUE_H */



