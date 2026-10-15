
#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char email[100];
    char phone[20];
    char town[50];
    char backup[100];
    char description[200];

    printf("Enter supplier name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);

    
town[strcspn(town, "\n")] = '\0';

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s", name);
    printf("Email: %s", email);
    printf("Phone: %s", phone);
    printf("Town : %s", town);

    
printf("\n--- STRING LENGTHS ---\n");
printf("Supplier name length: %zu\n", strlen(name) - 1);
printf("Email length: %zu\n", strlen(email) - 1);
printf("Town length: %zu\n", strlen(town) - 1);


char supplier1[] = "ABC Office Supplies";
char supplier2[] = "Namibia Stationery";
char searchName[100];


printf("\nEnter supplier name to search: ");
fgets(searchName, sizeof(searchName), stdin);
searchName[strcspn(searchName, "\n")] = '\0';

if (strcmp(searchName, supplier1) == 0 ||
    strcmp(searchName, supplier2) == 0) {
    printf("Supplier found.\n");
} else {
    printf("Supplier not found.\n");
}


printf("\n--- COPY SUPPLIER NAME ---\n");

strcpy(backup, name);

printf("Original name: %s\n", name);
printf("Backup name: %s\n", backup);


printf("\n--- SUPPLIER DESCRIPTION ---\n");

strcpy(description, name);
strcat(description, " operates in ");
strcat(description, town);
strcat(description, ".");

printf("%s\n", description);

int choice;

do {
    printf("\n================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Show Name Length\n");
    printf("5. Exit\n");
    printf("Enter choice: ");

    scanf("%d", &choice);

    switch (choice) {
                case 1:
            printf("Enter supplier name: ");
            scanf(" %99[^\n]", name);

            printf("Enter email: ");
            scanf(" %99[^\n]", email);

            printf("Enter phone: ");
            scanf(" %19[^\n]", phone);

            printf("Enter town: ");
            scanf(" %49[^\n]", town);
            break;

        case 2:
            printf("\n--- SUPPLIER DETAILS ---\n");
            printf("Name: %s\n", name);
            printf("Email: %s\n", email);
            printf("Phone: %s\n", phone);
            printf("Town: %s\n", town);
            break;

       case 3:
            char searchName[100];

            printf("Enter supplier name to search: ");
            scanf(" %99[^\n]", searchName);

            if (strcmp(searchName, "ABC Office Supplies") == 0 ||
                strcmp(searchName, "Namibia Stationery") == 0) {
                printf("Supplier found.\n");
            } else {
                printf("Supplier not found.\n");
            }
            break;

        
        case 4:
            printf("Supplier name length: %zu\n", strlen(name));
            break;
        

       

        case 5:
            printf("Exiting Supplier Management.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

} while (choice != 5);

return 0;
}
 

