#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4




void markVisited(int i, int *visited) {
    *visited = *visited | (1 << i);
}


int isVisited(int i, int visited) {
    return ((visited & (1 << i)) != 0);
}


int tsp(int graph[][V], int start, int visited, int dp[][V]) {
    
    if (visited == (1 << V) - 1) {
        return graph[start][0];
    }

   
    if (dp[visited][start] != -1) {
        return dp[visited][start];
    }

    int minCost = INT_MAX;

    
    for (int v = 0; v < V; v++) {
        if (!isVisited(v, visited)) {
            int new_state = visited | (1 << v);
            int cost = graph[start][v] + tsp(graph, v, new_state, dp);
            if (cost < minCost) {
                minCost = cost;
            }
        }
    }

    
    dp[visited][start] = minCost;
    return minCost;
}

int main() {
    
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }

   
    int start = 0;
    int visited = 1 << start;

    
    int minCost = tsp(graph, start, visited, dp);

   
    printf("The minimum weight Hamiltonian Cycle has weight: %d\n", minCost);

    return 0;
}

