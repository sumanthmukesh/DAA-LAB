#include <stdio.h>

#define MAX 64

void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int i, j;

    int A11[MAX][MAX], A12[MAX][MAX];
    int A21[MAX][MAX], A22[MAX][MAX];

    int B11[MAX][MAX], B12[MAX][MAX];
    int B21[MAX][MAX], B22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX];
    int M4[MAX][MAX], M5[MAX][MAX], M6[MAX][MAX];
    int M7[MAX][MAX];

    int T1[MAX][MAX], T2[MAX][MAX];
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

   
    addMatrix(A11, A22, T1, k);
    addMatrix(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

  
    addMatrix(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

   
    subtractMatrix(B12, B22, T2, k);
    strassen(A11, T2, M3, k);
    subtractMatrix(B21, B11, T2, k);
    strassen(A22, T2, M4, k);
    addMatrix(A11, A12, T1, k);
    strassen(T1, B22, M5, k);
    subtractMatrix(A21, A11, T1, k);
    addMatrix(B11, B12, T2, k);
    strassen(T1, T2, M6, k);
    subtractMatrix(A12, A22, T1, k);
    addMatrix(B21, B22, T2, k);
    strassen(T1, T2, M7, k);
    addMatrix(M1, M4, T1, k);
    subtractMatrix(T1, M5, T2, k);
    addMatrix(T2, M7, T1, k);
  for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            C[i][j] = T1[i][j];
    addMatrix(M3, M5, T1, k);
    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            C[i][j + k] = T1[i][j];
    addMatrix(M2, M4, T1, k);
    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            C[i + k][j] = T1[i][j];
    subtractMatrix(M1, M2, T1, k);
    addMatrix(T1, M3, T2, k);
    addMatrix(T2, M6, T1, k);
    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            C[i + k][j + k] = T1[i][j];
}
int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, i, j;

    printf("Enter matrix size (power of 2): ");
    scanf("%d", &n);

    printf("Enter Matrix A:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    strassen(A, B, C, n);
    printf("\nResult Matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n"); }

    return 0;
}
