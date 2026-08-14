#include <stdio.h>

int main() {
    int a[100], b[100], visited[100];
    int n, k;
    int i, j, min, minIndex;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        visited[i] = 0;
    }
    printf("Enter K: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        min=99999;
        minIndex = -1;
        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        }
        b[i] = min;
        visited[minIndex] = 1;
    }

    printf("The %dth smallest element is %d\n", k, b[k - 1]);

    return 0;
}