#include <stdio.h>
#include "utilities.h"

int readInt(const char *prompt)
{
    int value;

    printf("%s", prompt);
    scanf("%d", &value);

    return value;
}

float readFloat(const char *prompt)
{
    float value;

    printf("%s", prompt);
    scanf("%f", &value);

    return value;
}