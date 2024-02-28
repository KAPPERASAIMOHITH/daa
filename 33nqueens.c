#include <stdio.h>

int count = 0; 


int is_safe(int row, int col, int board[8][8]) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }

    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return 0;
        }
        i--;
        j--;
    }

    i = row - 1, j = col + 1;
    while (i >= 0 && j < 8) {
        if (board[i][j] == 1) {
            return 0;
        }
        i--;
        j++;
    }

    return 1;
}


void print_solution(int board[8][8]) {
    printf("\nSolution %d:\n", ++count);
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 1) {
                printf(" 1 ");
            } else {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
}


void solve(int row, int board[8][8], int limit) {
    if (count == limit) {
        return; 
    }

    if (row == 8) {
        print_solution(board);
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (is_safe(row, col, board)) {
            board[row][col] = 1;
            solve(row + 1, board, limit);
            board[row][col] = 0; 
        }
    }
}

int main() {
    int board[8][8] = {0};
    int limit;
    printf("Enter the limit on the number of solutions to print: ");
    scanf("%d", &limit);
    solve(0, board, limit);
    return 0;
}

