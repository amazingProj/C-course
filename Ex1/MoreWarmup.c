#include<stdio.h>
#include<stdbool.h>

/**
 * @brief function covert lower case letters to upper case
 *
 * @param input - a by reference string.
 *
 */
void ToUpperCase(char *input);

/**
 * @brief function deletes the first char from a string.
 * 
*  @param input - a by reference string
 * 
*/
void Shift(char *input);

/**
 *
 * function deletes from given string the initial spaces.
 * @param input - a by reference string
 *
 */
void RemoveInitialSpaces(char *input);

/**
 *
 * main function gets a string from user and print it to stdout until
 * the user use 'q' or 'Q' to exit.
 *
 */
int main() {
/*
 *  stdin input
 */
    char input[100];
    bool alive = true;

    do {
        printf("Enter a string.\n For exiting use 'q' or 'Q'");

        scanf("%s", input);


        RemoveInitialSpaces(&input);
        if ((input[0] == 'q' || input[0] == 'Q') && input[1] == '\0')
            alive = false;
        else
        {
            ToUpperCase(&input);
            printf("%s\n", input);
        }


    } while (alive);

    return 0;
}

void Shift(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        input[i] = input[i + 1];
        ++i;
    }
}

void RemoveInitialSpaces(char *input) {
    int i = 0;
    bool alive = true;
    do {
        ' ' == input[i] ? (Shift(&input)) : (alive = false);
        ++i;
    } while (alive);
}

void ToUpperCase(char *input) {
    int i = 0;

    while (input[i] != '\0') {
        if (input[i] >= 'a' && input[i] <= 'z')
            input[i] = input[i] - 32;
        ++i;
    }
