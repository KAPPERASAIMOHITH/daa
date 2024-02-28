#include <stdio.h>
#include <math.h>

int isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            if (i * i != num)
                sum += (i + num / i);
            else
                sum += i;
        }
    }
    if (sum == num)
        return 1;
    else
        return 0;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPerfect(num))
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);
    return 0;
}

