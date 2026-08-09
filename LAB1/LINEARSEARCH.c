#include <stdio.h>
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;       } 
 }
    return  0; 
  }
int main() {
    int size = 6, target, result;
    int arr[] = {12, 45,10, 19, 28, 32};
    printf("Enter the number to search: ");
    scanf("%d", &target);
    result = linearSearch(arr, size, target);
    if (result != 0) {
        printf("Element %d found at index position %d\n", target, result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}