#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/test.h"

int main(){

    srand((unsigned int)time(NULL));

    FILE *results_file = fopen("results.txt", "w");
    FILE *times_file = fopen("times.txt", "w");
    fprintf(results_file, "N TS W1 W2 W3 W4 W5 WU\n");
    fprintf(times_file, "N TS W1 W2 W3 W4 W5 WU\n");
    
    for (int N = 512; N <= 50000; N *= 2) {
        
        struct Task *dag = generate_random_DAG(N);
        clock_t start, end;
        double result, elapsed;
        
        start = clock();
        result = TEST_topological_sort(dag, N);
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(results_file, "%d %lf ", N, result);
        fprintf(times_file, "%d %lf ", N, elapsed);
        
        for (int workers = 1; workers <= 5; workers++) {
            start = clock();
            result = TEST_limited_workers(dag, N, workers);
            end = clock();
            elapsed = (double)(end - start) / CLOCKS_PER_SEC;
            fprintf(results_file, "%lf ", result);
            fprintf(times_file, "%lf ", elapsed);
        }
        
        start = clock();
        result = TEST_unlimited_workers(dag, N);
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(results_file, "%lf\n", result);
        fprintf(times_file, "%lf\n", elapsed);

        free_random_DAG(dag, N);
    }
    
    fclose(results_file);
    fclose(times_file);
}




