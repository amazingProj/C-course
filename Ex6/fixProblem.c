/******************************************************************************
the former code:


#include <stdio.h>
#include <stdlib.h>

int ErrorCodeToString(int code, char *errorMessage)
{
    switch (code)
    {
        case 0:
           errorMessage = "SUCCESS";
        case 1: 
           errorMessage = "File not found";
            break;
        default:
           return 0;
    }
    return 1;
}
int main()
{
    int errorCode = 1;
    char *msg = NULL;
    
    int retCode = ErrorCodeToString(errorCode, msg);
    
    printf("Function returned %s (error code %d\n",
    msg, errorCode);

    return 0;
}

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int ErrorCodeToString(int code, char **errorMessage)
{
    switch (code)
    {
        case 0:
           *errorMessage = "SUCCESS";
        case 1: 
           *errorMessage = "File not found";
            break;
        default:
           return 0;
    }
    return 1;
}
int main()
{
    int errorCode = 1;
    char *msg = NULL;
    
    int retCode = ErrorCodeToString(errorCode, &msg);
    
    printf("Function returned %s (error code %d\n",
    msg, errorCode);

    return 0;
}
