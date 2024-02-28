#include <stdio.h>

int findMaxRec(int arr[], int n);

int main() {
    int arr[] = {12, 34, 64, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = findMaxRec(arr, n);
    printf("The maximum element in the array is: %d\n", max);
    return 0;
}

int findMaxRec(int arr[], int n) {
    if (n == 1)
        return arr[0];
    
    int max = findMaxRec(arr, n - 1);
    
    if (arr[n - 1] > max)
        return arr[n - 1];
    else
        return max;
}

