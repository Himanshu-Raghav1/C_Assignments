#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char src_name[100], dst_name[100];

    printf("Enter source file name: ");
    scanf("%s", src_name);

    printf("Enter destination file name: ");
    scanf("%s", dst_name);

    FILE *src = fopen(src_name, "r");
    if (src == NULL)
    {
        printf("Error: Could not open source file '%s'.\n", src_name);
        return 1;
    }

    FILE *dst = fopen(dst_name, "w");
    if (dst == NULL)
    {
        printf("Error: Could not open destination file '%s'.\n", dst_name);
        fclose(src);
        return 1;
    }

    int ch;
    while ((ch = fgetc(src)) != EOF)
    {
        fputc(ch, dst);
    }

    fclose(src);
    fclose(dst);

    printf("File copied successfully.\n");
    printf("Contents of '%s' have been copied to '%s'.\n", src_name, dst_name);

    return 0;
}
