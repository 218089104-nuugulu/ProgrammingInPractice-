#include <stdio.h>
char municipality[50];
char mayor[50];
int population;

int main()
{
    printf("Municipal Financial Management System\n");
    printf("Welcome to Windhoek Municipality.\n");

    printf("\nEnter Municipality Name: ");
    scanf("%s" , municipality);

    printf("Enter Mayor's Name: ");
    scanf("%s" ,mayor);

    printf("Enter Population: ");
    scanf("%d", &population);

    printf("\n\n-----Municipal Report-----\n");
    printf("Municipality Name: %s\n",municipality);
    printf("Mayor's Name: %s\n" ,mayor);
    printf("Population: %d\n" ,population);

    return 0;
}