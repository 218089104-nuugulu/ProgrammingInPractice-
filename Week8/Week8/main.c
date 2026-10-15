#include <stdio.h>

/* Function declarations */
void displayWelcome(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void displayMenu(void);
int searchEmployee(int id, int ids[], int size);

int main(void)
{
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int employeeID;
    int position;
    int size = sizeof(employeeIDs) / sizeof(employeeIDs[0]);

    float amount;
    float basic, housing, transport;
    float grossSalary;
    float revenue, expenses, balance;

    /* Task 1: Welcome message */
    displayWelcome();

    /* Task 6: Search for an employee */
    printf("\nEnter employee ID: ");
    scanf("%d", &employeeID);

    position = searchEmployee(employeeID, employeeIDs, size);

    if (position != -1)
    {
        printf("Employee found at position %d\n", position);
    }
    else
    {
        printf("Employee not found.\n");
    }

    /* Repeat the menu until the user exits */
    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                /* Task 2: Calculate VAT */
                printf("Enter amount: ");
                scanf("%f", &amount);

                printf("VAT: %.2f\n", calculateVAT(amount));
                break;

            case 2:
                /* Task 3: Calculate gross salary */
                printf("Basic salary: ");
                scanf("%f", &basic);

                printf("Housing allowance: ");
                scanf("%f", &housing);

                printf("Transport allowance: ");
                scanf("%f", &transport);

                grossSalary = calculateSalary(
                    basic, housing, transport
                );

                printf("Gross salary: %.2f\n", grossSalary);
                break;

            case 3:
                /* Task 4: Calculate budget balance */
                printf("Enter revenue: ");
                scanf("%f", &revenue);

                printf("Enter expenses: ");
                scanf("%f", &expenses);

                balance = calculateBudget(revenue, expenses);

                printf("Balance: %.2f\n", balance);

                if (balance > 0)
                {
                    printf("SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("DEFICIT\n");
                }
                else
                {
                    printf("BALANCED\n");
                }
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

/* Task 1: Display welcome message */
void displayWelcome(void)
{
    printf("Welcome to the Municipal Financial Management System\n");
}

/* Task 2: Calculate VAT at 15 percent */
float calculateVAT(float amount)
{
    return amount * 0.15f;
}

/* Task 3: Return gross salary */
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

/* Task 4: Return revenue minus expenses */
float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

/* Task 5: Display reusable menu */
void displayMenu(void)
{
    printf("\n==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

/* Task 6: Return employee position, or -1 if not found */
int searchEmployee(int id, int ids[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }

    return -1;
}
