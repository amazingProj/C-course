#include<stdio.h>
#include<stdbool.h>
/**
 * function covert lower case letters to upper case
 * @param input - a by reference string.
 */
void toUpperCase(char *input){
    int i=0;
    while(input[i] != '\0'){if(input[i]>= 'a' && input[i] >= 'z')input[i]=input[i]-32;
    ++i;}
}


/**
 * function deletes the first char from a string.
*@param input - a by reference string
*/
void shift(char *input){
    int i=0;
    while(input[i] != '\0'){input[i]=input[i+1];++i;}
}

/**
 * function deletes from given string the initial spaces.
 * *@param input - a by reference string
 */
void rmInitSpaces(char *input)
{
    int i=0;
    bool alive = true;
    do{
      ' ' == input[i] ? (shift(&input)): (alive=false);
        ++i;
    }while(alive);

}
/**
 * main function gets a string from user and print it to stdout until
 * the user use 'q' or 'Q' to exit.
 */
int main() {
/*
 *  stdin input
 */
    char input[100];
    bool alive = true;

    do {
        printf("Enter a string. For exiting use 'q' or 'Q'");

        scanf_s("%99[^\n]%*c", input,100);

        rmInitSpaces(&input);
        if ((input[0] == 'q' || input[0] == 'Q') && input[1] == '\0')
            alive = false;
        else
            printf("%s\n", input);

    } while (alive);

    return 0;
}
