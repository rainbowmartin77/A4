#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1000000000
#define NUM_THREADS 1

double a = 0.0;
double b = 1.0;
double h;
double total_sum = 0.0;
pthread_mutex_t mutex;

double f(double x) {
    return 4.0 / (1.0 + x * x);
}

void *parallel_trapezoidalRule(void *arg) {
    int id = *(int*)arg;
    int intervalsPerThread = N / NUM_THREADS;
    double local_start = a + id * intervalsPerThread * h;
    double local_end = local_start + intervalsPerThread * h;
    double area = 0.0;

    area += (f(local_start) + f(local_end)) / 2.0;

    for (int i = 1; i < intervalsPerThread; i++) {
        area += f(local_start + i * h);
    }

    area *= h;

    pthread_mutex_lock(&mutex);
    total_sum += area;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread[NUM_THREADS];
    int threadID[NUM_THREADS];

    h = (b - a) / N;
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        threadID[i] = i;
        pthread_create(&thread[i], NULL, parallel_trapezoidalRule, &threadID[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread[i], NULL);
    }

    printf("Result of numerical integration: %.15f\n", total_sum);

    pthread_mutex_destroy(&mutex);
    return 0;
}