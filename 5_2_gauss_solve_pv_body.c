#include <math.h>

void MyGaussSolve (int n, double A[n][n], double b[n], double x[n]) {
    int i, j, k;
    double dtemp, dmax, tmpx[n];
    int list[n], nmax, ntemp;

    for (k=0; k<n; k++) list[k] = k;

    /* zenshin */
    for (k=0; k<n-1; k++) {
        nmax = k;
        dmax = fabs(A[list[k]][k]);
        for (i=k+1; i<n; i++) {
            if (dmax < fabs(A[list[i]][k])) {
                nmax = i;
                dmax = fabs(A[list[i]][k]);
            }
        }

        if (k != nmax) {
            ntemp = list[k]; list[k] = list[nmax]; list[nmax] = ntemp;
        }

        dtemp = 1.0 / A[list[k]][k];
        for (i=k+1; i<n; i++) {
            A[list[i]][k] = A[list[i]][k] * dtemp;
        }

        for (j=k+1; j<n; j++) {
            dtemp = A[list[j]][k];
            for (i=k+1; i<n; i++) {
                A[list[j]][i] = A[list[j]][i] - A[list[k]][i] * dtemp;
            }
            b[list[j]] = b[list[j]] - b[list[k]] * dtemp;
        }
    }

    /* koutai*/
    tmpx[list[n-1]] = b[list[n-1]] / A[list[n-1]][n-1];
    for (k=n-2; k>=0; k--) {
        tmpx[list[k]] = b[list[k]];
        for (j=k+1; j<n; j++) {
            tmpx[list[k]] -= A[list[k]][j] * tmpx[list[j]];
        }
        tmpx[list[k]] = tmpx[list[k]] / A[list[k]][k];
    }

    for (k=0; k<n; k++) x[k] = tmpx[list[k]];
}