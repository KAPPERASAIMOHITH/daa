#include <stdio.h>
#include <limits.h>

#define N 4
int minCost(int costMatrix[N][N], int row, int assigned[N], int totalCost, int minCostSoFar) {
    if (row == N) {
        return totalCost < minCostSoFar ? totalCost : minCostSoFar;
    }

    for (int col = 0; col < N; col++) {
        if (!assigned[col]) {
            assigned[col] = 1;
            int currentCost = minCost(costMatrix, row + 1, assigned, totalCost + costMatrix[row][col], minCostSoFar);
            assigned[col] = 0;
            if (currentCost < minCostSoFar) {
                minCostSoFar = currentCost;
            }
        }
    }

    return minCostSoFar;
}

int jobAssignment(int costMatrix[N][N]) {
    int assigned[N];
    for (int i = 0; i < N; i++) {
        assigned[i] = 0;
    }
    return minCost(costMatrix, 0, assigned, 0, INT_MAX);
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int minCost = jobAssignment(costMatrix);
    printf("Minimum cost of job assignment: %d\n", minCost);

    return 0;
}



