#include <stdio.h>
#include <string.h>

#define MAX 100

int string_length(char s[]);
void string_reverse(char s[], char rev[]);
int strings_equal(char s1[], char s2[]);
int is_palindrome(char s[]);
int is_substring(char main_str[], char sub[]);

int main(void)
{
    char s1[MAX], s2[MAX];

    printf("Enter a string: ");
    scanf(" %[^\n]", s1);

    printf("Enter another string (for equality and substring check): ");
    scanf(" %[^\n]", s2);

    printf("\nLength of \"%s\" = %d\n", s1, string_length(s1));

    char rev[MAX];
    string_reverse(s1, rev);
    printf("Reversed string = %s\n", rev);

    if (is_palindrome(s1))
    {
        printf("\"%s\" is a Palindrome\n", s1);
    }
    else
    {
        printf("\"%s\" is NOT a Palindrome\n", s1);
    }

    if (strings_equal(s1, s2))
    {
        printf("Strings are Equal\n");
    }
    else
    {
        printf("Strings are NOT Equal\n");
    }

    if (is_substring(s1, s2))
    {
        printf("\"%s\" IS a substring of \"%s\"\n", s2, s1);
    }
    else
    {
        printf("\"%s\" is NOT a substring of \"%s\"\n", s2, s1);
    }

    return 0;
}

int string_length(char s[])
{
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

void string_reverse(char s[], char rev[])
{
    int len = string_length(s);

    for (int i = 0; i < len; i++)
    {
        rev[i] = s[len - 1 - i];
    }

    rev[len] = '\0';
}

int strings_equal(char s1[], char s2[])
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return 0;
        }
        i++;
    }

    return s1[i] == '\0' && s2[i] == '\0';
}

int is_palindrome(char s[])
{
    char rev[MAX];
    string_reverse(s, rev);
    return strings_equal(s, rev);
}

int is_substring(char main_str[], char sub[])
{
    int main_len = string_length(main_str);
    int sub_len  = string_length(sub);

    if (sub_len > main_len)
    {
        return 0;
    }

    for (int i = 0; i <= main_len - sub_len; i++)
    {
        int match = 1;

        for (int j = 0; j < sub_len; j++)
        {
            if (main_str[i + j] != sub[j])
            {
                match = 0;
                break;
            }
        }

        if (match)
        {
            return 1;
        }
    }

    return 0;
}
