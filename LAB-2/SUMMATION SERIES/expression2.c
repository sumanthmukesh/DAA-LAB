#include <stdio.h>

int main() {
    int n, i;
    double x, term = 1, sum = 0;
    printf("Enter X: ");
    scanf("%lf", &x);
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        sum += term;
        term *= x;
    }
    printf("Sum = %.2lf\n", sum);
    return 0;
}