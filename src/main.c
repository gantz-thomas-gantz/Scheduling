#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/test.h"
#include "../include/graph.h"

int main(){
    srand((unsigned int)time(NULL));

    int N = 10000;
    struct Task *dag = malloc(N*sizeof(struct Task));
    generate_random_DAG(dag,N);
    free_random_DAG(dag,N);

    printf("done\n");
}