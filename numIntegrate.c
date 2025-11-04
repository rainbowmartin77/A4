#include <stdio.h>

#define N 1000000000 // intervals

double f(double x) {
    return 4.0 / (1.0 + x * x); // Function to integrate
}

double trapezoidalRule() 
{
    // Upper limit and lower limit
    double start = 0.0;
    double end = 1.0;

    // Width of each trapezoid
    double trapWidth = end / N;
    // Total of trapezoid areas
    double total = 0.0;

    // First point contributes half
    total += f(start) / 2;

    // Loop through the middle trapezoids
    for (int i = 1; i < N; i++) {
        // Calculate trapezoid area
        double trap = start + i * trapWidth;
        total += f(trap);
    }

    // Last point contributes half
    total += f(end)/2;

    // Total area multiplied by the width of each trapezoid
    return total * trapWidth;
}

int main() {
    double pi = trapezoidalRule();
    printf("Estimated value of π: %f\n", pi);
    return 0;
}
