#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n;

    printf("Enter how many random numbers you want: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Please enter a positive number.\n");
        return 1;
    }

    srand(time(0));

    printf("\nPseudo Random Numbers:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", rand());
    }

    return 0;
}
