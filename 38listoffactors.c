#include <stdio.h>
void generateFactors(int n, int currentFactor) {
    if (currentFactor > n) {
        return;
    }

    if (n % currentFactor == 0) {
        printf("%d ", currentFactor);
    }

    generateFactors(n, currentFactor + 1); 
}
void listAllFactors(int n) {
    generateFactors(n, 1);
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    printf("Factors of %d are: ", n);
    listAllFactors(n);
    
    return 0;
}


