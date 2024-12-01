#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/test.h"

int main(){

    srand((unsigned int)time(NULL));
    // Time on different graphs!!!
    printf("TEST_schedule_end_limited_workers(10000,1): %lf\n", TEST_schedule_end_limited_workers(10000,1));
    printf("TEST_schedule_end_limited_workers(10000,2): %lf\n", TEST_schedule_end_limited_workers(10000,2));
    printf("TEST_schedule_end_limited_workers(10000,3): %lf\n", TEST_schedule_end_limited_workers(10000,3));
    printf("TEST_schedule_end_unlimited_workers(10000): %lf\n", TEST_schedule_end_unlimited_workers(10000));
}