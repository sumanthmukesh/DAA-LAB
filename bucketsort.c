#include <stdio.h>

#define MAX 100

void bucketSort(int arr[], int n)
{
    int bucket[MAX] = {0};
    int max = arr[0];

    // Find the maximum element
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    // Store the frequency of each element
    for (int i = 0; i < n; i++)
        bucket[arr[i]]++;

    // Reconstruct the sorted array
    int index = 0;

    for (int i = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            arr[index++] = i;
            bucket[i]--;
        }
    }
}

int main()
{
    int arr[] = {42, 32, 33, 52, 37, 47, 51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
