#include <stdio.h>
#include <string.h>

int ispalindrome(char str[], int start, int end) {
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;
    return ispalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (ispalindrome(str, 0, strlen(str) - 1))
        printf("%s is a palindrome.", str);
    else
        printf("%s is not a palindrome.", str);
    return 0;
}

