#ifndef GRAPH_H
#define GRAPH_H

struct Task {
    double duration;
    double end;
    int req;    // current number of tasks that need to be finished before
    int ns;
    int *successors;       
};

void generate_random_DAG(struct Task* dag, int N);

void free_random_DAG(struct Task* dag, int N);

#endif /* GRAPH_H */
