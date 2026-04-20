#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int n);
void prime_factors(int n);

int main(void)
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Square = %d\n", number * number);
    printf("Cube = %d\n", number * number * number);

    if (number >= 0)
    {
        printf("Square Root = %.2f\n", sqrt(number));
    }
    else
    {
        printf("Square Root not defined for negative numbers.\n");
    }

    if (is_prime(number))
    {
        printf("It is a Prime number.\n");
    }
    else
    {
        printf("It is NOT a Prime number.\n");
    }

    if (number >= 0)
    {
        long long fact = 1;
        for (int i = 1; i <= number; i++)
        {
            fact *= i;
        }
        printf("Factorial = %lld\n", fact);
    }
    else
    {
        printf("Factorial not defined for negative numbers.\n");
    }

    printf("Prime Factors: ");
    prime_factors(number);
}

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void prime_factors(int n)
{
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n /= i;
        }
    }
    printf("\n");
}
