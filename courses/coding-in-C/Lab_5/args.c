#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    for(int i = 0; i < argc; i++)
    {
        unsigned short len = strlen(argv[i]);
        printf("Argument %d at address %p contains \"%s\" (length %d)\n", i, argv[i], argv[i], len);
    }

    for(int i = 0; i < argc; i++)
    {
        unsigned short len = strlen(*(argv + i));
        printf("Argument %d at address %p contains \"%s\" (length %d)\n", i, *(argv + i), *(argv + i), len);
    }
    return 0;
}