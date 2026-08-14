#include <stdio.h>
#include <math.h>
int main() {
    int n;
    double x, sum;
    printf("Enter X: ");
    scanf("%lf", &x);
    printf("Enter number of terms: ");
    scanf("%d", &n);
    if (x == 1)
        sum = n;
    else
        sum = (pow(x, n) - 1) / (x - 1);

    printf("Sum = %.2lf\n", sum);

    return 0;
}