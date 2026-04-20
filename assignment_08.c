#include <stdio.h>

int main(void)
{
    int marks[5];
    int sum = 0;
    int result = 0;
    for (int i=0;i<5;i++)
    {
        printf("Marks: ");
        scanf("%i", &marks[i]);
        sum += marks[i];
        if (marks[i]< 40)
        {
            result = -1;
        }
        else
        {
            result = 1;
        }
    }
    if (result == 1)
    {
        int total_marks = sum;
        float percentage = total_marks/5.0;
        printf("Percentage obtained: %f\n",percentage);
        if (percentage>= 75)
        {
            printf("Distinction\n");
        }
        else if (percentage>= 60 && percentage<=75)
        {
            printf("First Division\n");
        }
        else if (percentage>= 50 && percentage<=60)
        {
            printf("Second Division\n");
        }
        else if (percentage>= 40 && percentage<=50)
        {
            printf("Third Division\n");
        }
    }
    else
    {
        printf("Fail\n");
    }
}
