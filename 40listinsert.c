#include <stdio.h>

#define MAX_SIZE 100


void insertNumber(int list[], int *n, int position, int number) {
    if (position < 0 || position > *n) {
        printf("Invalid position\n");
        return;
    }

    
    for (int i = *n; i > position; i--) {
        list[i] = list[i-1];
    }

    list[position] = number; 
    (*n)++; 
}


void displayList(int list[], int n) {
    printf("List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];
    int n, position, number;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter the elements of the list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    printf("Enter the position to insert the number: ");
    scanf("%d", &position);

    printf("Enter the number to insert: ");
    scanf("%d", &number);

    insertNumber(list, &n, position, number);
    displayList(list, n);

    return 0;
}

