#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void generatePascalTriangle(int numRows) {
    int triangle[numRows][numRows];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                triangle[i][j] = 1;
            else
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    
    printf("Pascal's Triangle for %d rows:\n", numRows);
    for (int i = 0; i < numRows; i++) {
        for (int space = 0; space < numRows - i; space++)
            printf("  ");
        for (int j = 0; j <= i; j++) {
            printf("%4d", triangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numRows = 5; 
    generatePascalTriangle(numRows);
    return 0;
}

