#include <stdio.h>
void printNumbers(int i) {
    if (i == 0)
        return;
    printNumbers(i - 1);
    printf("%d ", i);
}

void printPattern(int n) {
    if (n == 0)
        return;
    printPattern(n - 1);
    printNumbers(n);
    printf("\n");
}

int main() {
    int n = 4; 
    printPattern(n); 
    return 0;
}

