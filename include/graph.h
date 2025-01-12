#ifndef GRAPH_H
#define GRAPH_H

// Structure representing a task in the Directed Acyclic Graph (DAG)
struct Task {
    double duration;   // Execution time of the task (in arbitrary units)
    double end;        // Earliest completion time of the task (calculated during execution)
    int req;           // Number of prerequisite tasks that need to be completed before this one
    int ns;            // Number of successor tasks that depend on this task
    int *successors;   // Array holding the indices of successor tasks (tasks that depend on this one)
};

/**
 * @brief Prints the details of a given task.
 * 
 * @param task Pointer to the Task structure to be printed.
 */
void print_task(const struct Task* task);

/**
 * @brief Prints the details of all tasks in an array.
 * 
 * @param dag Pointer to the array of Task structures.
 * @param N Number of tasks in the array.
 */
void print_all_tasks(const struct Task* dag, int N);

/**
 * @brief Sets the requirements (number of prerequisites) for each task in the DAG.
 * 
 * @param dag Pointer to the array of Task structures.
 * @param N The number of tasks in the DAG.
 */
void set_req(struct Task *dag, int N);

/**
 * @brief Generates a random Directed Acyclic Graph (DAG) of tasks.
 * 
 * @param N The number of tasks in the DAG.
 * @return A pointer to the generated array of Task structures.
 */
struct Task *generate_random_DAG(int N);

/**
 * @brief Frees the memory allocated for a random DAG.
 * 
 * @param dag Pointer to the array of Task structures.
 * @param N The number of tasks in the DAG.
 */
void free_random_DAG(struct Task* dag, int N);

#endif /* GRAPH_H */

