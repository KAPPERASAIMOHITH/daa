#include <stdio.h>

#define MAX_SIZE 100

void printMinMaxSequences(int arr[], int n) {
    int minSeq[MAX_SIZE], maxSeq[MAX_SIZE];
    int i, j;

    for (i = 0; i < n; i++) {
        int num = arr[i];
        int minCount = 0, maxCount = 0;

        for (j = i - 1; j >= 0; j--) {
            if (arr[j] < num)
                minSeq[minCount++] = arr[j];
        }


        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > num)
                maxSeq[maxCount++] = arr[j];
        }

        printf("Minimum sequence for %d: ", num);
        for (j = minCount - 1; j >= 0; j--)
            printf("%d ", minSeq[j]);
        printf("\n");

        printf("Maximum sequence for %d: ", num);
        for (j = maxCount - 1; j >= 0; j--)
            printf("%d ", maxSeq[j]);
        printf("\n\n");
    }
}

int main() {
    int arr[] = {5, 2, 7, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printMinMaxSequences(arr, n);

    return 0;
}

