#include <stdio.h>

#define MAX 100

int main(void)
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input. Enter between 1 and %d.\n", MAX);
        return 1;
    }

    int arr[MAX];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEven numbers: ");
    int found_even = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d ", arr[i]);
            found_even = 1;
        }
    }
    if (!found_even)
    {
        printf("None");
    }

    printf("\nOdd numbers:  ");
    int found_odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            printf("%d ", arr[i]);
            found_odd = 1;
        }
    }
    if (!found_odd)
    {
        printf("None");
    }

    printf("\n");
    return 0;
}
