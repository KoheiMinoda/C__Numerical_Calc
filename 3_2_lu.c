void MyLUsolve (int n, double A[n][n], double b[n], double u[n]) {
  double c[n];
  int i, j, k;
  double dtemp;

  /* LU */
  for (k = 0; k < n-1; k++) {
    dtemp = 1.0 / A[k][k];
    for (i = k+1; i < n; i++) {
      A[i][k] *= dtemp;
    }
    for (j = k+1; j < n; j++) {
      dtemp = A[j][k];
      for (i = k+1; i<n; i++) {
        A[j][i] -= A[k][i] * dtemp;
      }
    }
  }

  /* zenshin */
  for (k = 0; k <n; k++) {
    c[k] = b[k];
    for (j = 0; j < k; j++) {
      c[k] -= A[k][j] * c[j];
    }
  }

  /* koutai */
  u[n-1] = c[n-1]/A[n-1][n-1];
  for (k = n-2; k >= 0; k--) {
    u[k] = c[k];
    for (j = k+1; j < n; j++) {
      u[k] -= A[k][j] * u[j];
    }
    u[k] = u[k] / A[k][k];
  }
}
