#include <stdio.h>
/**
 *        assumption: Do not print the termination number: 0
 * @brief function prints all of given number in reverse order
 *        noticed that function gets numbers until 0 is given.
 * @see   url about how to safely get  a number
 *        https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1043372399&id=1043284385
 */
void Reverse()
{
    int num;
    printf("now put the number");
    //from the url
    while (scanf("%d", &num) != 1)
    {
        while (getchar() != '\n');
        printf ("Try again: ");
    }
    //break condition
    if (num == 0)
    {
        return;
    }
    //recursion before loop gives us reverse order
    Reverse();
    printf("%d ",num);

}


/**
 * @brief function runs Reverse.
 * @see Reverse()
 * @return 0 when terminates.
 */
int main() {
    printf("Enter any numbers, but 0 to terminate loop \n");
    Reverse();
    return 0;
}
