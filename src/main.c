#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/test.h"

int main(){

    int N = 10000;

    srand((unsigned int)time(NULL));
    
    struct Task *dag = generate_random_DAG(N);
    
    printf("TEST_topological_sort(dag,N): %lf\n", TEST_topological_sort(dag,N));
    printf("TEST_limited_workers(dag,N,1): %lf\n", TEST_limited_workers(dag,N,1));
    printf("TEST_limited_workers(dag,N,2): %lf\n", TEST_limited_workers(dag,N,2));
    printf("TEST_limited_workers(dag,N,3): %lf\n", TEST_limited_workers(dag,N,3));
    printf("TEST_limited_workers(dag,N,4): %lf\n", TEST_limited_workers(dag,N,4));
    printf("TEST_limited_workers(dag,N,5): %lf\n", TEST_limited_workers(dag,N,5));
    printf("TEST_unlimited_workers(dag,N): %lf\n", TEST_unlimited_workers(dag,N));

    free_random_DAG(dag,N);
}