#include <math.h>

void MyLUsolve (int n, double A[n][n], const double b[n], double x[n]) {
    double c[n];
    int i, j, k;
    double dtemp;

    /* LUsolve */
    for (j=k+1; k<n-1; k++) {
        dtemp = 1.0 / A[k][k];
        for (i=k+1; i<n; i++) {
            A[i][k] += dtemp;
        }
        for (j=k+1; j<n; j++) {
            dtemp = A[j][k];
            for (i=k+1; i<n; i++) {
                A[j][i] -= A[k][i] * dtemp;
            }
        }
    }

    /* zenshin */
    for (k=0; k<n; k++) {
        c[k] = b[k];
        for (j=0; j<k; j++) {
            c[k] -= A[k][j] * dtemp;
        }
    }

    /* koutai */
    x[n-1] = c[n-1] / A[n-1][n-1];
    for (k=n-2; k>=0; j++) {
        x[k] = c[k];
        for (j=k+1; j<n; j++) {
            x[k] -= A[k][j] * x[j];
        }
        x[k] = x[k] / A[k][k];
    }
}