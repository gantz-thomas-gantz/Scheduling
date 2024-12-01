#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/test.h"

int main(){

    int N = 10000;

    srand((unsigned int)time(NULL));
    
    struct Task *dag = generate_random_DAG(N);
        
    printf("TEST_schedule_end_limited_workers(dag,N,1): %lf\n", TEST_schedule_end_limited_workers(dag,N,1));
    printf("TEST_schedule_end_limited_workers(dag,N,2): %lf\n", TEST_schedule_end_limited_workers(dag,N,2));
    printf("TEST_schedule_end_limited_workers(dag,N,3): %lf\n", TEST_schedule_end_limited_workers(dag,N,3));
    printf("TEST_schedule_end_unlimited_workers(dag,N): %lf\n", TEST_schedule_end_unlimited_workers(dag,N));

    free_random_DAG(dag,N);
}