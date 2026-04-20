#include <stdio.h>
#include <string.h>

#define MAX 100

void display_menu(void);

int main(void)
{
    char s1[MAX], s2[MAX];

    printf("Enter first string : ");
    scanf(" %[^\n]", s1);

    printf("Enter second string: ");
    scanf(" %[^\n]", s2);

    int choice;

    do
    {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Length of \"%s\" = %lu\n", s1, strlen(s1));
                break;

            case 2:
            {
                char copy[MAX];
                strcpy(copy, s1);
                printf("Copied string: %s\n", copy);
                break;
            }

            case 3:
            {
                char concat[MAX * 2];
                strcpy(concat, s1);
                strcat(concat, s2);
                printf("Concatenated string: %s\n", concat);
                break;
            }

            case 4:
            {
                int result = strcmp(s1, s2);
                if (result == 0)
                {
                    printf("Strings are EQUAL\n");
                }
                else if (result < 0)
                {
                    printf("\"%s\" comes BEFORE \"%s\" lexicographically\n", s1, s2);
                }
                else
                {
                    printf("\"%s\" comes AFTER \"%s\" lexicographically\n", s1, s2);
                }
                break;
            }

            case 5:
            {
                char rev[MAX];
                int len = strlen(s1);
                for (int i = 0; i < len; i++)
                {
                    rev[i] = s1[len - 1 - i];
                }
                rev[len] = '\0';
                printf("Reversed string: %s\n", rev);
                break;
            }

            case 0:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    while (choice != 0);

    return 0;
}

void display_menu(void)
{
    printf("\nString Operations Menu\n");
    printf("1. Length of string\n");
    printf("2. Copy string\n");
    printf("3. Concatenate strings\n");
    printf("4. Compare strings\n");
    printf("5. Reverse string\n");
    printf("0. Exit\n");
}
