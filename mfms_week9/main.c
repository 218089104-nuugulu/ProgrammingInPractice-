#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"
#include "storage.h"

int main(void)
{
    int choice;
    int ids[100] = {101, 102, 103, 104, 105};
    int size = 5;
    int id;
    int position;
    float revenue;
    float expenses;
    float balance;

    Employee employees[100];
    int employeeCount = 5;
    int i;

    for (i = 0; i < employeeCount; i++)
    {
        employees[i].id = ids[i];
        snprintf(employees[i].name, sizeof employees[i].name,
                 "Employee%d", ids[i]);
        employees[i].salary = 0.0;
    }

    do
    {
       printf("1. Search Employee\n");
printf("2. Calculate Budget\n");
printf("3. Display Financial Report\n");
printf("4. Save Data (Text)\n");
printf("5. Load Data (Text)\n");
printf("6. Save Data (Binary)\n");
printf("7. Load Data (Binary)\n");
printf("8. Backup Data\n");
printf("9. Exit\n");

        choice = readInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                id = readInt("Enter employee ID: ");
                position = searchEmployee(id, ids, size);

                if (position != -1)
                    printf("Employee found at position %d.\n",
                           position + 1);
                else
                    printf("Employee not found.\n");
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
                saveEmployeesText(employees, employeeCount);
                break;

            case 5:
                employeeCount =
                    loadEmployeesText(employees, 100);

                for (i = 0; i < employeeCount; i++)
                    ids[i] = employees[i].id;

                size = employeeCount;
                break;

           case 6:
    saveEmployeesBinary(employees, employeeCount);
    break;

case 7:
    employeeCount = loadEmployeesBinary(employees, 100);

    for (i = 0; i < employeeCount; i++)
        ids[i] = employees[i].id;

    size = employeeCount;
    break;

case 8:
    backupEmployeesText();
    break;

case 9:
    printf("Exiting MFMS. Goodbye!\n");
    break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    }  while (choice != 9);

    return 0;
}