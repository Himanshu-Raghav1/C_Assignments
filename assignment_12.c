#include <stdio.h>

int gcd(int a, int b);
int smallest_common_divisor(int a, int b);

int main(void)
{
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0)
    {
        printf("Please enter positive integers.\n");
        return 1;
    }

    int scd = smallest_common_divisor(a, b);
    if (scd == -1)
    {
        printf("Smallest Common Divisor (other than 1): None\n");
    }
    else
    {
        printf("Smallest Common Divisor (other than 1): %d\n", scd);
    }

    printf("Greatest Common Divisor (GCD): %d\n", gcd(a, b));

    return 0;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

int smallest_common_divisor(int a, int b)
{
    int limit = (a < b) ? a : b;

    for (int i = 2; i <= limit; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }

    return -1;
}
