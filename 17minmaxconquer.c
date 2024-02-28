#include <stdio.h>
struct MinMax {
    int min;
    int max;
};
struct MinMax findMinMax(int arr[], int low, int high) {
    struct MinMax result, left, right, middle;
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    if (high - low == 1) {
        result.min = (arr[low] < arr[high]) ? arr[low] : arr[high];
        result.max = (arr[low] > arr[high]) ? arr[low] : arr[high];
        return result;
    }
    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;
    
    return result;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct MinMax result = findMinMax(arr, 0, n - 1);
    printf("Minimum: %d\n", result.min);
    printf("Maximum: %d\n", result.max);
    
    return 0;
}

