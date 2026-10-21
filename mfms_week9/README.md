# Municipal Financial Management System (MFMS) — Week 9

## Project Description

This project demonstrates how to modularise a C program by separating its functionality into different source files and header files.

## Project Modules

- `main.c` — Displays the main menu and coordinates the program.
- `employees.c` and `employees.h` — Search for employees by ID.
- `budget.c` and `budget.h` — Calculate the remaining budget.
- `utilities.c` and `utilities.h` — Read integer and decimal input.
- `reports.c` and `reports.h` — Display the financial report.

## Requirements

- GCC compiler
- C99-compatible compiler

## Compilation

Compile each source file:

```bash
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
```

Link the object files:

```bash
gcc main.o employees.o budget.o utilities.o reports.o -o mfms
```

Run the program:

```bash
./mfms
```

On Windows PowerShell, run the program using:

```powershell
.\mfms.exe
```

## Menu Options

1. Search Employee
2. Calculate Budget
3. Display Financial Report
4. Exit

## Testing

The program was tested by searching for an employee ID, calculating a remaining budget, displaying a financial report, and exiting through the menu.

## Learning Objective

The objective is to practise modular programming in C using separate source files, header files, function declarations, compilation, and linking.