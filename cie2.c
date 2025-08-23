// mp prg to tramform each element with A[i]=3*A[i]+2 using # pragma omp paralle for schedule (dynamic,2) then switch  to (static,2)
// int A1[6]={1,2,3,4,5,6};dynamic,2
// int A2[6]={1,2,3,4,5,6};static,2
#include <stdio.h>
#include <omp.h>

int main() {
 
    int A1[6] = {1, 2, 3, 4, 5, 6};
    int A2[6] = {1, 2, 3, 4, 5, 6};

    
    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < 6; i++) {
        A1[i] = 3 * A1[i] + 2;
    }

    printf("Array A1 after dynamic scheduling:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", A1[i]);
    }
    printf("\n");

    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < 6; i++) {
        A2[i] = 3 * A2[i] + 2;
    }

    printf("Array A2 after static scheduling:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", A2[i]);
    }
    printf("\n");

    return 0;
}
