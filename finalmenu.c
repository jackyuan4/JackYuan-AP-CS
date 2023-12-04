// Nov 17, 2023
// Worked with Emrick throughout the Project
// Thanks!

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE1 5000
#define SIZE2 10000
#define SIZE3 50000
int *readFile(string fileName, int size, int size2); // pointer to return and int array
int linearSearch(int array[], int guess, int size);  // linear search
int binarySearch(int array[], int size, int number);
int *bubbleSort(int array[], int size);
int *selectionSort(int array[], int size);
void printArray(int array[], int size);
void Menu();
int main(void)
{
    string fileName;
    int choice;
    int binaryIndex;

    do
    {
        Menu();
        choice = get_int("Please enter your choice 1-5: ");

        switch (choice)
        {
            case 1:
                fileName = "random5000.txt";
                int linearGuess = get_int("Search for what number using linear search: ");
                int *linearArray = readFile(fileName, SIZE2, 5);
                int linearindex = linearSearch(linearArray, linearGuess, SIZE2);
                if (linearindex != -1)
                    printf("Number %d is in index %d\n", linearGuess, linearindex);
                else
                    printf("Number %d is not in index\n", linearGuess);
                break;

            case 2:
                fileName = "sorted5000.txt";
                int *binaryArray = readFile(fileName, SIZE2, 5);
                int binaryGuess = get_int("Search for what number using binary search: ");
                binaryIndex = binarySearch(binaryArray, SIZE2, binaryGuess);
                if (binaryIndex != -1)
                {
                    printf("Number %d is in index %d\n", binaryGuess, binaryIndex);
                }
                else
                {
                    printf("Your number is not in index.\n");
                }
                break;

            case 3:
                fileName = "random5000.txt";
                int *selectionArray = readFile(fileName, SIZE2, 5);
                selectionSort(selectionArray, SIZE2);
                printf("Selection Sort Array:\n");
                printArray(selectionArray, SIZE2);
                break;

            case 4:
                fileName = "random5000.txt";
                int *bubblearray = readFile(fileName, SIZE2, 5);
                bubbleSort(bubblearray, SIZE2);
                printf("Bubble sort array:\n");
                printArray(bubblearray, SIZE2);
                break;

            case 5:
                printf("Exiting...\n");
                break;
        }
    }
    while (choice != 5);

    return 0;
}
int *readFile(string fileName, int size, int size2)
{

    FILE *file = (fopen(fileName, "r"));

    char line[size2];
    char options[size][size2];

    int static numbers[SIZE2]; // file to be returned

    for (int i = 0; i < size; i++)
    {
        fscanf(file, "%s", options[i]);
        // printf("%s \n", options[i]);
        numbers[i] = atoi(options[i]);
    }
    fclose(file);
    return numbers;
}
int linearSearch(int array[], int guess, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == guess)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int array[], int size, int number)
{
    int highest = 4999;
    int lowest = 0;
    int midnum;

    while (lowest <= highest)
    {
        midnum = (highest + lowest) / 2; // find middle number

        if (array[midnum] == number)
        {
            return midnum;
        }
        else if (array[midnum] < number)
        {
            lowest = midnum + 1;
        }
        else
        {
            highest = midnum - 1;
        }
    }
    return -1;
}
int *selectionSort(int array[], int size)
{
    int indx = 0;
    for (int i = 0; i < size; i++)
    {
        int min = size + 1;
        for (int j = i; j < size; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                indx = j;
            }
        }
        // make the swap
        int temp = array[i];
        array[i] = min;
        array[indx] = temp;
    }
    return array;
}
int *bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %i \n", array[i]);
    }
}
void Menu()
{
    printf("=====================================\n");
    printf("#               MENU                #\n");
    printf("#   1) Do Linear Search             #\n");
    printf("#   2) Do binary search             #\n");
    printf("#   3) Do selection sort            #\n");
    printf("#   4) Do Bubble sort               #\n");
    printf("#   5) Exit                         #\n");
    printf("=====================================\n");
}
