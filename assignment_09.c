#include <stdio.h>

int main(void)
{
    int number;
    printf("Enter a three-digit number: ");
    scanf("%d", &number);

    if (number < 100 || number > 999)
    {
        printf("Please enter a valid three-digit number.\n");
        return 1;
    }

    int original = number;
    int sum = 0;

    while (number > 0)
    {
        int digit = number % 10;
        sum += digit * digit * digit;
        number /= 10;
    }

    if (sum == original)
    {
        printf("%d is an Armstrong number.\n", original);
    }
    else
    {
        printf("%d is NOT an Armstrong number.\n", original);
    }
}
