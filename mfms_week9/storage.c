
#include <stdio.h>
#include "storage.h"

void saveEmployeesText(const Employee employees[], int count)
{
    FILE *fp = fopen("data/employees.txt", "w");

    if (fp == NULL)
    {
        perror("data/employees.txt");
        return;
    }

    int saved = 0;

    for (int i = 0; i < count; i++)
    {
        if (fprintf(fp, "%d|%s|%.2f\n",
                    employees[i].id,
                    employees[i].name,
                    employees[i].salary) < 0)
        {
            printf("Error writing employee record.\n");
            fclose(fp);
            return;
        }

        saved++;
    }

    if (fclose(fp) != 0)
    {
        perror("Error closing text file");
        return;
    }

    printf("%d employee record(s) saved.\n", saved);
}


int loadEmployeesText(Employee employees[], int capacity)
{
    FILE *fp = fopen("data/employees.txt", "r");

    if (fp == NULL)
    {
        perror("data/employees.txt");
        return 0;
    }

    int loaded = 0;
    int lineNumber = 0;
    char line[200];

    while (loaded < capacity && fgets(line, sizeof line, fp) != NULL)
    {
        lineNumber++;

        int id;
        char name[50];
        double salary;
        char extra;

        if (sscanf(line, "%d|%49[^|]|%lf %c",
                   &id, name, &salary, &extra) == 3)
        {
            employees[loaded].id = id;

            snprintf(employees[loaded].name,
                     sizeof employees[loaded].name, "%s", name);

            employees[loaded].salary = salary;
            loaded++;
        }
        else
        {
            printf("Malformed record on line %d. Skipping it.\n",
                   lineNumber);
        }
    }

    if (ferror(fp))
    {
        perror("Error reading employee file");
    }

    fclose(fp);

    printf("%d employee record(s) loaded.\n", loaded);

    return loaded;
}


void saveEmployeesBinary(const Employee employees[], int count)
{
    FILE *fp = fopen("data/employees.dat", "wb");

    if (fp == NULL)
    {
        perror("data/employees.dat");
        return;
    }

    size_t saved = fwrite(employees, sizeof(Employee),
                          (size_t)count, fp);

    if (fclose(fp) != 0)
    {
        perror("Error closing binary file");
        return;
    }

    if (saved != (size_t)count)
    {
        printf("Error saving all employee records.\n");
    }
    else
    {
        printf("%d employee record(s) saved to binary file.\n",
               count);
    }
}

int loadEmployeesBinary(Employee employees[], int capacity)
{
    FILE *fp = fopen("data/employees.dat", "rb");
    int loaded = 0;

    if (fp == NULL)
    {
        perror("data/employees.dat");
        return 0;
    }

    while (loaded < capacity &&
           fread(&employees[loaded], sizeof(Employee), 1, fp) == 1)
    {
        loaded++;
    }

    fclose(fp);

    printf("%d employee record(s) loaded from binary file.\n",
           loaded);

    return loaded;
}  

void backupEmployeesText(void)
{
    FILE *source = fopen("data/employees.txt", "r");

    if (source == NULL)
    {
        perror("Could not open employee text file");
        return;
    }

    FILE *backup = fopen("data/employees_backup.txt", "w");

    if (backup == NULL)
    {
        perror("Could not create backup file");
        fclose(source);
        return;
    }

    int ch;

    while ((ch = fgetc(source)) != EOF)
    {
        if (fputc(ch, backup) == EOF)
        {
            printf("Error writing backup file.\n");
            fclose(source);
            fclose(backup);
            return;
        }
    }

    fclose(source);
    fclose(backup);

    printf("Employee data backed up successfully.\n");
}

