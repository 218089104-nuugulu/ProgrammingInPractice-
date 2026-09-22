#include <stdio.h>
#include <string.h>

int main()
{
    // A. Employee salaries
    float salaries[50];
    float totalSalary = 0;
    float averageSalary;
    float highestSalary;
    float lowestSalary;
    float searchSalary;
    int salaryFound = 0;

    printf("===== EMPLOYEE SALARY MANAGEMENT =====\n\n");

    // Capture 50 salaries
    for (int i = 0; i < 50; i++)
    {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);

        totalSalary = totalSalary + salaries[i];

        if (i == 0)
        {
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        }

        if (salaries[i] > highestSalary)
        {
            highestSalary = salaries[i];
        }

        if (salaries[i] < lowestSalary)
        {
            lowestSalary = salaries[i];
        }
    }

    averageSalary = totalSalary / 50;

    // Display salaries
    printf("\n--- Employee Salaries ---\n");

    for (int i = 0; i < 50; i++)
    {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    // Display salary results
    printf("\n--- Salary Analysis ---\n");
    printf("Total salary: %.2f\n", totalSalary);
    printf("Average salary: %.2f\n", averageSalary);
    printf("Highest salary: %.2f\n", highestSalary);
    printf("Lowest salary: %.2f\n", lowestSalary);

    // Search for salary
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);

    for (int i = 0; i < 50; i++)
    {
        if (salaries[i] == searchSalary)
        {
            printf("Salary %.2f found for employee %d.\n",
                   searchSalary, i + 1);
            salaryFound = 1;
        }
    }

    if (salaryFound == 0)
    {
        printf("Salary %.2f was not found.\n", searchSalary);
    }

    // B. Department budgets
    float budgets[10];
    float totalBudget = 0;
    float averageBudget;
    float temp;

    printf("\n===== DEPARTMENT BUDGETS =====\n\n");

    // Capture 10 budgets
    for (int i = 0; i < 10; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);

        totalBudget = totalBudget + budgets[i];
    }

    averageBudget = totalBudget / 10;

    // Display budgets
    printf("\n--- Department Budgets ---\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    // Display budget results
    printf("\n--- Budget Analysis ---\n");
    printf("Total budget: %.2f\n", totalBudget);
    printf("Average budget: %.2f\n", averageBudget);

    // Sort budgets from lowest to highest
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (budgets[i] > budgets[j])
            {
                temp = budgets[i];
                budgets[i] = budgets[j];
                budgets[j] = temp;
            }
        }
    }

    printf("\n--- Budgets Sorted Lowest to Highest ---\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    // C. Vehicle registration numbers
    char registrations[20][20];
    char searchRegistration[20];
    int registrationFound = 0;

    printf("\n===== VEHICLE REGISTRATIONS =====\n\n");

    // Capture 20 registrations
    for (int i = 0; i < 20; i++)
    {
        printf("Enter registration number %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    // Display registrations
    printf("\n--- Vehicle Registration Numbers ---\n");

    for (int i = 0; i < 20; i++)
    {
        printf("Vehicle %d: %s\n", i + 1, registrations[i]);
    }

    // Search registration
    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchRegistration);

    for (int i = 0; i < 20; i++)
    {
        if (strcmp(registrations[i], searchRegistration) == 0)
        {
            printf("Registration %s found for vehicle %d.\n",
                   searchRegistration, i + 1);
            registrationFound = 1;
        }
    }

    if (registrationFound == 0)
    {
        printf("Registration %s was not found.\n", searchRegistration);
    }

    printf("\n===== PROGRAM COMPLETE =====\n");

    return 0;
}