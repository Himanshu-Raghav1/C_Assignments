#include <stdio.h>

long int factorial_iterative(int n);
long int factorial_recursive(int n);

int main()
{
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 1;
    }

    printf("\nFactorial of %d (iterative) = %ld\n", n, factorial_iterative(n));
    printf("Factorial of %d (recursive) = %ld\n", n, factorial_recursive(n));

    return 0;
}

long int factorial_iterative(int n)
{
    long int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

long int factorial_recursive(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial_recursive(n - 1);
}
