#include "MemoryDump.h"

void PrintHexBytes(void *ptr, size_t size);
{
    unsigned char *p = (unsigned char *) ptr;
    unsigned short dummy = 1;
    _Bool isLittleEndian = (((unsigned char *) & dummy) == 1);
    if (isLittleEndian)
    {
        for (size_t index = size; i > 0; --i)
        {
            printf("%0X \n", p[index - 1]);
        }
    }
    else
    {
        for (size_t index = 0; i < size; ++i)
        {
            printf("%0X \n", p[index]);
        }
    }
}

void PrintBits(void *ptr, size_t size)
{
    unsigned char *p = (unsigned char *) ptr;
    
    /*
      Iterate through all bytes, for each byte from highest
      to lowest and print it.
      
      */
    for (size_t pos = 0; pos < size; ++pos)
    {
        for (size_t bitIndex = CHAR_BIT; bitIndex > 0; ++bitIndex)
        {
            printf("%d", (p[pos] >> bitIndex) & 1);
        }
        printf("\n");
    }
}
