#ifndef GRAPH_H
#define GRAPH_H

struct Task {
    double duration;
    double end;
    int req;    // current number of tasks that need to be finished before
    int ns;
    int *successors;       
};

void print_task(const struct Task* task);

void print_all_tasks(const struct Task* dag, int N);

void generate_random_DAG(struct Task* dag, int N);

void free_random_DAG(struct Task* dag, int N);

#endif /* GRAPH_H */
