#ifndef STORAGE_H
#define STORAGE_H

#include "employees.h"

void saveEmployeesText(const Employee employees[], int count);
int loadEmployeesText(Employee employees[], int capacity);

void saveEmployeesBinary(const Employee employees[], int count);
int loadEmployeesBinary(Employee employees[], int capacity);
void backupEmployeesText(void);
#endif