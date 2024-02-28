
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
} Item;

int compare(const void *a, const void *b) {
    return (*(Item *)b).size - (*(Item *)a).size;
}

void loadContainers(Item items[], int n, int containerCapacity) {
    int containers = 0;
    int currentSize = 0;
    
    qsort(items, n, sizeof(Item), compare);

    for (int i = 0; i < n; i++) {
        if (currentSize + items[i].size <= containerCapacity) {
            currentSize += items[i].size;
        } else {
            containers++;
            currentSize = items[i].size;
        }
        printf("Item %d: Container %d\n", i+1, containers+1);
    }
    printf("Total containers used: %d\n", containers+1);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter the size of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].size);
    }

    int containerCapacity;
    printf("Enter the capacity of each container: ");
    scanf("%d", &containerCapacity);

    loadContainers(items, n, containerCapacity);

    return 0;
}


