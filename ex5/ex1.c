#include <stdio.h>
#include <string.h>
#define n 5

typedef struct Dod_s
{
    char* name;
    int kg;
} Dog;

/**
 *         determine which is first str1 or str2 in lexi- order
 * @param  str1 - a string
 * @param  str2 - a string
 * @return 1 - when str1 is first, 0 when str2 is first
 */
int LexicographicOrder(char* str1, char* str2)
{
    int strIndex = 0;
    while (str1[strIndex] == str2[strIndex])
    {
        if (str1[strIndex + 1] != '/0' && str2[strIndex + 1] == '/0')
        {
            return 0;
        }
        if (str1[strIndex + 1] == '/0' && str2[strIndex + 1] != '/0')
        {
            return 1;
        }
        if (str1[strIndex + 1] == '/0' && str2[strIndex + 1] == '/0')
        {
            return 1;
        }
        ++strIndex;
    }
    if (str1[strIndex] < str2[strIndex])
    {
        return 0;
    }
    // st1[strIndex] >= str[strIndex]
    return 1;
}

/**
 *        prints an array of dogs
 * @param arr - an array of dogs.
 */
void PrintDogs(Dog* arr)
{
    // prints the array
    for(int i = 0; i < n; ++i)
    {
        printf("%s %d\n", arr[i].name, arr[i].kg);
    }
}

/**
 *        assumption: descent lexicographic order: Z - A
 *        a function that sorts by name then prints
 * @param arr - an array of Dogs
 */
void SortDogByName(Dog* arr)
{
    int minIndex = 0;
    char minStr[20];
    Dog dog;

    // selection sort
    for(int i = 0; i < n - 1; ++i)
    {
        minIndex = i;
        strcpy_s(minStr, sizeof minStr, arr[i].name);

        for(int j = i + 1; j < n; ++j)
        {
            if (LexicographicOrder(minStr, arr[j].name) )
            {
                strcpy_s(minStr, sizeof minStr, arr[j].name);
                minIndex = j;
            }
        }

        //swap the minimum and current
        dog = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = dog;

    }

    // prints the array
    for(int i = 0; i < n; ++i)
    {
        printf("%s %d\n", arr[i].name, arr[i].kg);
    }

}

/**
 *        assumption: smallest to biggest
 *        a function that sort by k.g.
 * @param arr - an array of dogs
 */
void SortDogByKg(Dog* arr)
{
    int minIndex = 0;
    Dog dog;

    // selection sort: O(n^2) run time
    for(int i = 0; i < n; ++i)
    {

        minIndex = i;
        for(int j = i+1; j < n; ++j)
        {
            if (arr[j].kg < arr[minIndex].kg)
            {
                minIndex = j;
            }
        }


        //swap the former and current
        dog = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = dog;

    }

    // prints the array
    for(int i = 0; i < n; ++i)
    {
        printf("%s %d\n", arr[i].name, arr[i].kg);
    }



}

/**
 *         checks the functions below
 * @return 0 when terminated
 */
int main()
{

    const char* name[] =
            {
                    "Chivavha",
                    "Bulldog",
                    "Lavrador",
                    "Zebra",
                    "Appo",
            };

    int array[n] = {3, 1, 2, 5, 6};
    Dog dogs[n];

    for(int i = 0; i < n; ++i)
    {

        dogs[i].name = name[i];
        dogs[i].kg = array[i];


    }

    SortDogByName(dogs);
    printf("\n");
    SortDogByKg(dogs);

    printf("Finish!\n");
    return 0;
}
