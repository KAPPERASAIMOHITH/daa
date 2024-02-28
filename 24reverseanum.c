#include <stdio.h>
#include<math.h>
int reverseNumber(int num) {
    if (num < 10)
        return num;
    else {
        int lastDigit = num % 10;
        int remainingDigits = num / 10;
        int count = 0;
        int temp = remainingDigits;
        while (temp > 0) {
            count++;
            temp /= 10;
        }
        return lastDigit * pow(10, count) + reverseNumber(remainingDigits);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reverse of %d is %d\n", num, reverseNumber(num));
    return 0;
}

