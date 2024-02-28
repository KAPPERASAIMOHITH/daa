#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weights[], int values[], int n, int capacity) {
    int table[n+1][capacity+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                table[i][w] = 0;
            else if (weights[i - 1] <= w)
                table[i][w] = max(values[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w]);
            else
                table[i][w] = table[i - 1][w];
        }
    }

    return table[n][capacity];
}

int main() {
	int n,capacity;
	
	printf("enter the size of the array: ");
	scanf("%d",&n);
	int weights[n],values[n];
	printf("enter the weights:");
	for(int i=0;i<n;i++){
		scanf("%d",&weights[i]);
		
	}
	printf("enter the values:");
	for(int i=0;i<n;i++){
		scanf("%d",&values[i]);
		
	}
	printf("enter the capacity: ");
	scanf("%d",&capacity);

    
    printf("Maximum value that can be obtained is %d\n", knapsack(weights, values, n, capacity));
    return 0;
}

