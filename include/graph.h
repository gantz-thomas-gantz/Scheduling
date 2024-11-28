struct Task {
    double duration;
    double start;
    int req;    // current number of tasks that need to be finished before
    int ns;
    int *successors;       
};

void generate_random_DAG(struct Task* dag, int N);

void free_random_DAG(struct Task* dag, int N);
