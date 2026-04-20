#include <stdio.h>

void swap_by_value(int a, int b);
void swap_by_reference(int *a, int *b);

int main(void)
{
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("\nSwap Without Pointers (Call by Value)\n");
    printf("Before: a = %d, b = %d\n", a, b);
    swap_by_value(a, b);
    printf("After : a = %d, b = %d  (original unchanged)\n", a, b);

    printf("\nSwap With Pointers (Call by Reference)\n");
    printf("Before: a = %d, b = %d\n", a, b);
    swap_by_reference(&a, &b);
    printf("After : a = %d, b = %d\n", a, b);

    return 0;
}

void swap_by_value(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    printf("Inside function: a = %d, b = %d  (local swap only)\n", a, b);
}

void swap_by_reference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
