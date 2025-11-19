#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define N_ITERATIONS 1000000

int funcio() {
    return 20;
}

int main() {

    struct timespec start, end;
    double totalTimeSysCall, totalTimeFuncCall;
    float avgTimeSysCall, avgTimeFuncCall;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < N_ITERATIONS; i++) {
        funcio();
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    totalTimeFuncCall = (end.tv_nsec - start.tv_nsec);
    avgTimeFuncCall = totalTimeFuncCall / N_ITERATIONS;

    printf("Temps mitjà de la funció: %f ns\n", avgTimeFuncCall);


    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < N_ITERATIONS; i++) {
        getpid();
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    totalTimeSysCall = (end.tv_nsec - start.tv_nsec);
    avgTimeSysCall = totalTimeSysCall / N_ITERATIONS;

    printf("Temps mitjà de la crida a sistema: %f ns\n", avgTimeSysCall);

    return 0;
}