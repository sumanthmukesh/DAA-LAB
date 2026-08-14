#include <stdio.h>
int main() {
    int a[100], n, k, i, j, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter K: ");
    scanf("%d", &k);
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;   }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;}
    printf("The %dth smallest element is %d\n", k, a[k - 1]);
    return 0;
}