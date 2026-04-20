#include <stdio.h>

int binary_to_decimal(long int binary);
int is_valid_binary(long int binary);

int main(void)
{
    long int binary;

    printf("Enter a binary number: ");
    scanf("%ld", &binary);

    if (!is_valid_binary(binary))
    {
        printf("Error: Invalid binary number. Use only 0s and 1s.\n");
        return 1;
    }

    printf("Decimal equivalent = %d\n", binary_to_decimal(binary));

    return 0;
}

int is_valid_binary(long int binary)
{
    if (binary == 0)
    {
        return 1;
    }

    long int temp = binary;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (digit != 0 && digit != 1)
        {
            return 0;
        }

        temp /= 10;
    }

    return 1;
}

int binary_to_decimal(long int binary)
{
    int decimal = 0;
    int base = 1;
    long int temp = binary;

    while (temp > 0)
    {
        int digit = temp % 10;
        decimal += digit * base;
        base *= 2;
        temp /= 10;
    }

    return decimal;
}
