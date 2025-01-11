#include <stdlib.h>
#include <stdio.h>

#include "../include/graph.h"

#include <stdio.h>

/**
 * @brief Prints the details of a given task.
 * 
 * @param task Pointer to the Task structure to be printed.
 */
void print_task(const struct Task* task) {
    if (task == NULL) {
        printf("Task is NULL.\n");
        return;
    }

    printf("Task Details:\n");
    printf("  Duration: %.2f\n", task->duration);
    printf("  End: %.2f\n", task->end);
    printf("  Requirements (req): %d\n", task->req);
    printf("  Number of Successors (ns): %d\n", task->ns);

    if (task->ns > 0 && task->successors != NULL) {
        printf("  Successors: ");
        for (int i = 0; i < task->ns; ++i) {
            printf("%d", task->successors[i]);
            if (i < task->ns - 1) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("  No successors.\n");
    }
}

/**
 * @brief Prints the details of all tasks in an array.
 * 
 * @param tasks Pointer to the array of Task structures.
 * @param n Number of tasks in the array.
 */
void print_all_tasks(const struct Task* tasks, int n) {
    if (tasks == NULL || n <= 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("Printing all tasks (%d total):\n", n);
    for (int i = 0; i < n; ++i) {
        printf("Task %d:\n", i);
        print_task(&tasks[i]);
        printf("\n"); // Add a blank line between tasks for readability
    }
}


static int fill_array(int *array, int size, int start) {
    // Initialize the random number generator
    int count1 = 0;
    for (int i = start; i < size; i++) {
        // Randomly assign 0 or 1
        int val = rand() % 2;
        array[i] = val;
        if(val==1){
            count1++;
        }
    }
    return count1;
}

/**
 * @brief Generates a random double within the specified range.
 * 
 * @param min The lower bound of the range.
 * @param max The upper bound of the range.
 * @return A random double between min and max.
 */
static double random_double(double min, double max) {
    if (min > max) {
        // Swap if the range is invalid
        double temp = min;
        min = max;
        max = temp;
    }

    // Generate a random double in the range [min, max]
    return min + (rand() / (double)RAND_MAX) * (max - min);
}

struct Task *generate_random_DAG(int N) {
    struct Task *dag = malloc(N * sizeof(struct Task));
    
    // Create N random tasks
    for (int i = 0; i < N; i++) {
        struct Task *task = malloc(sizeof(struct Task));
        int *neighbors = calloc(N, sizeof(int));

        // Fill adjacency array, only allowing successors from i+1 onward to maintain DAG property
        task->ns = fill_array(neighbors, N, i + 1);

        task->duration = random_double(1.0, 10.0);
        task->end = -1.0;
        task->req = 0;
        task->successors = malloc(task->ns * sizeof(int));

        // Copy successor indices
        int place = 0;
        for (int j = 0; j < N; j++) {
            if (neighbors[j] == 1) {
                task->successors[place++] = j;
            }
        }

        free(neighbors);
        dag[i] = *task;
        free(task);
    }

    return dag;
}

void set_req(struct Task *dag, int N){
    for(int task_idx=0; task_idx<N; task_idx++){
        for(int k=0; k<dag[task_idx].ns; k++){
            int successor_idx = dag[task_idx].successors[k];
            dag[successor_idx].req++;
        }
    }
}

/**
 * @brief Frees the memory allocated for a random DAG.
 * 
 * @param dag Pointer to the array of Task structures.
 * @param N Number of tasks in the DAG.
 */
void free_random_DAG(struct Task* dag, int N) {
    for (int i = 0; i < N; i++) {
        // Free the memory allocated for the successors array of each task
        free(dag[i].successors);
    }
    // Free the memory allocated for the entire DAG array
    free(dag);
}
