#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100


void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}


void subsetSum(int set[], int subset[], int n, int subsetSize, int sum, int targetSum, int ite) {
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
        
        subsetSum(set, subset, n, subsetSize - 1, sum - set[ite], targetSum, ite + 1);
        return;
    } else {
        for (int i = ite; i < n; i++) {
            subset[subsetSize] = set[i];
            
            subsetSum(set, subset, n, subsetSize + 1, sum + set[i], targetSum, i + 1);
        }
    }
}


void findSubsets(int set[], int n, int targetSum) {
    int subset[MAX_SIZE];
    subsetSum(set, subset, n, 0, 0, targetSum, 0);
}

int main() {
    int set[] = {7,9,10,6,5,3};
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 16;

    printf("Subsets with sum %d are:\n", targetSum);
    findSubsets(set, n, targetSum);

    return 0;
}

