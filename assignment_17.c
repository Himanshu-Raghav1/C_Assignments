#include <stdio.h>
#include <math.h>

double sine_series(double x, int terms);
long int factorial(int n);

int main(void)
{
    double x;
    int terms;

    printf("Enter value of x (in radians): ");
    scanf("%lf", &x);

    printf("Enter number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0)
    {
        printf("Number of terms must be positive.\n");
        return 1;
    }

    double result = sine_series(x, terms);

    printf("\nSum of sine series  = %.6lf\n", result);
    printf("sin(x) from math.h  = %.6lf\n", sin(x));

    return 0;
}

long int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    long int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

double sine_series(double x, int terms)
{
    double sum = 0.0;
    int sign = 1;
    int power = 1;

    for (int i = 0; i < terms; i++)
    {
        sum += sign * (pow(x, power) / factorial(power));
        sign *= -1;
        power += 2;
    }

    return sum;
}
