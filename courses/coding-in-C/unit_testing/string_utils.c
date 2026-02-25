#include <stdio.h>
#include <stdlib.h>

#include "string_utils.h"

int custom_len(const char *string)
{
    int i = 0;
    while(*(string+i) != '\0')
    {
        i++;
    }
    return i;
}

char* read_line_dynamic()
{
    char input[100];
    if(fgets(input, sizeof(input), stdin) == NULL)
    {
        return NULL;
    }
    int len = custom_len(input);
    char *myString = malloc((len+1) * sizeof(char));
    if (myString != NULL) 
    {
        for(int i = 0; i <= len; i++) 
        {
            *(myString + i) = *(input + i);
        }
    }
    return myString;
}