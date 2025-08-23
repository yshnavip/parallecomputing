#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int is_prime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the upper limit (n): ");
    scanf("%d", &n);

    if (n < 2) {
        printf("There is no prime number ≤ %d.\n", n);
        return 0;
    }

    printf("\nFinding the largest prime ≤ %d...\n", n);

    // Sequential version
    double start_time = omp_get_wtime();

    int largest_prime_seq = -1;
    for (int i = n; i >= 2; i--) {
        if (is_prime(i)) {
            largest_prime_seq = i;
            break;  // OK in sequential
        }
    }

    double time_seq = omp_get_wtime() - start_time;
    printf("Sequential: Largest prime ≤ %d is %d (found in %f seconds)\n",
           n, largest_prime_seq, time_seq);

    // Parallel version
    start_time = omp_get_wtime();

    int largest_prime_par = -1;
    #pragma omp parallel for reduction(max:largest_prime_par) schedule(dynamic)
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            if (i > largest_prime_par) {
                largest_prime_par = i;
            }
        }
    }

    double time_par = omp_get_wtime() - start_time;
    printf("Parallel:   Largest prime ≤ %d is %d (found in %f seconds)\n",
           n, largest_prime_par, time_par);

    return 0;
}
