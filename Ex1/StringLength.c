#include <stdio.h>

/**
 * My own implementation of strlen of c library
 * @param string - a given string
 * @return the length of the string.
 */
int StringLength(const char *string)
{
    int i=0;
    while (string[i])
    {
        ++i;
    }
    return i;
}

/**
 * Checks the function StringLength
 * @return 0 - when terminated
 */
int main()
{
    char *string = "Hello from c   _____    129287";
    int i = StringLength(string);
    
    printf("%d",i);
    
    return 0;
}
