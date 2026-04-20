#include <stdio.h>

void reverse_digits(int n);

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Note: Using absolute value for negative input.\n");
        n = -n;
    }

    printf("Digits in reverse order: ");
    reverse_digits(n);
    printf("\n");

    return 0;
}

void reverse_digits(int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    }

    while (n > 0)
    {
        int digit = n % 10;
        printf("%d ", digit);
        n /= 10;
    }
}
