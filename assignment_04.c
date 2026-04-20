#include <stdio.h>

int main(void)
{
    float basic, hra, ta, gross, tax, net;
    printf("Enter Basic Pay: ");
    scanf("%f", &basic);
    hra = 0.10 * basic;
    ta = 0.05 * basic;
    gross = basic + hra + ta;
    tax = 0.02 * gross;
    net = gross - tax;
    
    printf("HRA = %.2f\n", hra);
    printf("TA = %.2f\n", ta);
    printf("Gross Salary = %.2f\n", gross);
    printf("Professional Tax = %.2f\n", tax);
    printf("Net Salary = %.2f\n", net);
}
