#include <stdio.h>

struct pair
{
    int max;
    int min;
};

struct pair findmin_max(int arr[], int low, int high)
{
    struct pair result, left, right;

    // Only one element
    if (low == high)
    {
        result.min = result.max = arr[low];
        return result;
    }

    // Two elements
    else if (high == low + 1)
    {
        if (arr[high] > arr[low])
        {
            result.max = arr[high];
            result.min = arr[low];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }

        return result;
    }

    // More than two elements
    else
    {
        int mid = (low + high) / 2;

        left = findmin_max(arr, low, mid);
        right = findmin_max(arr, mid + 1, high);

        result.max = left.max > right.max ? left.max : right.max;
        result.min = left.min < right.min ? left.min : right.min;

        return result;
    }
}

int main()
{
    int n, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct pair result = findmin_max(arr, 0, n - 1);

    printf("Maximum element = %d\n", result.max);
    printf("Minimum element = %d\n", result.min);

    return 0;
}