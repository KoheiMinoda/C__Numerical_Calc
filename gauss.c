#include <stdio.h>

#define N 10

int main() {
    double A[N][N], b[N];
    int i, j, ii;

    for (j=0; j<N; j++) {
        ii = 0;
        for (i=j; i<N; i++) {
            A[j][i] = (N - j) - ii;
            A[i][j] = A[j][i];
            ii++;
        }
    }

    printf("Matrix A:\n");
    for (j=0; j<N; j++) {
        for (i=0; i<N; i++) {
            printf(" %5.2f", A[j][i]);
        }
        printf("\n");
    }

    for (i=0; i<N; i++) {
        b[i] = 0.0;
        for (j=0; j<N; j++) {
            b[i] += A[i][j];
        }
    }

    printf("Vector b:\n");
    for (i=0; i<N; i++) {
        printf(" %5.2f", b[i]);
    }
    printf("\n");
    return 0;
}