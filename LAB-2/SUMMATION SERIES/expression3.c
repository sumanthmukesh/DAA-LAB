#include <stdio.h>

int main() {
    int n, x, i, j;
    int power, sum = 0;
    printf("Enter X: ");
    scanf("%d", &x);
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        power = 1;
        for (j = 0; j < i; j++) {
            power = power * x;
        }
        sum = sum + power;
    }
    printf("Sum = %d\n", sum);

    return 0;
}