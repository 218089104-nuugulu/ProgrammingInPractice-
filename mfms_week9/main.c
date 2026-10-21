#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void)
{
    int choice;
    int ids[] = {101, 102, 103, 104, 105};
    int size = 5;
    int id;
    int position;
    float revenue;
    float expenses;
    float balance;

    do
    {
        printf("\n===== MFMS MENU =====\n");
        printf("1. Search Employee\n");
        printf("2. Calculate Budget\n");
        printf("3. Display Financial Report\n");
        printf("4. Exit\n");

        choice = readInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                id = readInt("Enter employee ID: ");
                position = searchEmployee(id, ids, size);

                if (position != -1)
                {
                    printf("Employee found at position %d.\n",
                           position + 1);
                }
                else
                {
                    printf("Employee not found.\n");
                }
                break;

            case 2:
                revenue = readFloat("Enter total revenue: ");
                expenses = readFloat("Enter total expenses: ");
                balance = calculateBudget(revenue, expenses);

                printf("Remaining budget: %.2f\n", balance);
                break;

            case 3:
                revenue = readFloat("Enter total revenue: ");
                expenses = readFloat("Enter total expenses: ");
                displayReport(revenue, expenses);
                break;

            case 4:
                printf("Exiting MFMS. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}