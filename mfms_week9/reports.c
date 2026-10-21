#include <stdio.h>
#include "reports.h"

void displayReport(float revenue, float expenses)
{
    float balance = revenue - expenses;

    printf("\n===== MFMS FINANCIAL REPORT =====\n");
    printf("Total Revenue:  %.2f\n", revenue);
    printf("Total Expenses: %.2f\n", expenses);
    printf("Remaining Balance: %.2f\n", balance);
    printf("================================\n");
}