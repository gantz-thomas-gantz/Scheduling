#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/test.h"

int main(){
    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Open files to store results and execution times
    FILE *results_file = fopen("results.txt", "w");
    FILE *times_file = fopen("times.txt", "w");
    
    // Print headers to the result files
    fprintf(results_file, "N TS TS(SJF) W1 W2 W3 W4 W5 WU\n");
    fprintf(times_file, "N TS TS(SJF) W1 W2 W3 W4 W5 WU\n");

    // Loop over different sizes of the Directed Acyclic Graph (DAG) from 512 to 50000
    for (int N = 512; N <= 50000; N *= 2) {

        // Generate a random DAG with N tasks
        struct Task *dag = generate_random_DAG(N);
        clock_t start, end;
        double result, elapsed;

        // Measure execution time for topological sort
        start = clock();
        result = TEST_topological_sort(dag, N);
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(results_file, "%d %lf ", N, result);  // Print result to file
        fprintf(times_file, "%d %lf ", N, elapsed);  // Print execution time to file

        // Measure execution time for SJF (Shortest Job First) topological sort
        start = clock();
        result = TEST_topological_sort_SJF(dag, N);
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(results_file, "%lf ", result);  // Print result to file
        fprintf(times_file, "%lf", elapsed);    // Print execution time to file

        // Measure execution time for limited worker configurations (1 to 5 workers)
        for (int workers = 1; workers <= 5; workers++) {
            start = clock();
            result = TEST_limited_workers(dag, N, workers);
            end = clock();
            elapsed = (double)(end - start) / CLOCKS_PER_SEC;
            fprintf(results_file, "%lf ", result);  // Print result to file
            fprintf(times_file, "%lf ", elapsed);   // Print execution time to file
        }

        // Measure execution time for unlimited workers configuration
        start = clock();
        result = TEST_unlimited_workers(dag, N);
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(results_file, "%lf\n", result);  // Print result to file
        fprintf(times_file, "%lf\n", elapsed);   // Print execution time to file

        // Free the memory allocated for the random DAG
        free_random_DAG(dag, N);
    }

    // Close the result and time files
    fclose(results_file);
    fclose(times_file);
}





