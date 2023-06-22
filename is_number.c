#include "monty.h"

int is_number(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    int i = 0;
    if (str[0] == '-')
        i = 1;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1;
}

