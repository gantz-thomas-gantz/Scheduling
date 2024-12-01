#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/test.h"

int main(){
    srand((unsigned int)time(NULL));
    printf("TEST_schedule_end_unlimited_workers(10): %lf\n", TEST_schedule_end_unlimited_workers(10));
    printf("TEST_schedule_end_limited_workers(1000,10): %lf\n", TEST_schedule_end_limited_workers(1000,10));
}