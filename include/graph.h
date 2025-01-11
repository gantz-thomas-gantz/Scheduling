#ifndef GRAPH_H
#define GRAPH_H

struct Task {
    double duration;   // Execution time of the task  
    double end;        // Earliest completion time of the task  
    int req;           // Number of prerequisite tasks 
    int ns;            // Number of successor tasks  
    int *successors;   // Array of indices of successor tasks  
};

void print_task(const struct Task* task);
void print_all_tasks(const struct Task* dag, int N);

void set_req(struct Task *dag, int N);
struct Task *generate_random_DAG(int N);
void free_random_DAG(struct Task* dag, int N);

#endif /* GRAPH_H */
