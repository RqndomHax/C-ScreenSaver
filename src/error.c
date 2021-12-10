#include <stdio.h>

#include "../includes/error.h"

void *exit_function(char *errorMessage, int *errorCode, int error)
{
    *errorCode = error;
    perror(errorMessage);
    return (((void *)0)); // NULL stdlib.h macro
}