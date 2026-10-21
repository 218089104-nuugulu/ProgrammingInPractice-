#ifndef EMPLOYEES_H
#define EMPLOYEES_H

typedef struct
{
    int id;
    char name[50];
    double salary;
} Employee;

int searchEmployee(int id, int ids[], int size);

#endif