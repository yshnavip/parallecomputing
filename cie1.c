// write an open mp prg which launches a parallel and it had each tread print its ID and team size
#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
         int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        printf("Thread ID: %d, Team Size: %d\n", thread_id, num_threads);
    }

    return 0;
}
