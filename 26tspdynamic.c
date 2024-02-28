#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4

// Number of vertices in the graph

// Function to mark the vertex v as visited
void markVisited(int i, int *visited) {
    *visited = *visited | (1 << i);
}

// Function to check if the vertex v is visited or not
int isVisited(int i, int visited) {
    return ((visited & (1 << i)) != 0);
}

// Function to find the minimum weight Hamiltonian Cycle
int tsp(int graph[][V], int start, int visited, int dp[][V]) {
    // If all vertices have been visited, return the cost of returning to the start vertex
    if (visited == (1 << V) - 1) {
        return graph[start][0];
    }

    // If the result is already computed, return it
    if (dp[visited][start] != -1) {
        return dp[visited][start];
    }

    int minCost = INT_MAX;

    // Try all unvisited vertices
    for (int v = 0; v < V; v++) {
        if (!isVisited(v, visited)) {
            int new_state = visited | (1 << v);
            int cost = graph[start][v] + tsp(graph, v, new_state, dp);
            if (cost < minCost) {
                minCost = cost;
            }
        }
    }

    // Save the result
    dp[visited][start] = minCost;
    return minCost;
}

int main() {
    // Example graph representation
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Initialize the dp table with -1
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }

    // Start the traversal from vertex 0
    int start = 0;
    int visited = 1 << start;

    // Find the minimum weight Hamiltonian Cycle
    int minCost = tsp(graph, start, visited, dp);

    // Output the result
    printf("The minimum weight Hamiltonian Cycle has weight: %d\n", minCost);

    return 0;
}

