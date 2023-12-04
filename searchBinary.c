#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Read NO SORTED file
//Load it in an Array
// Ask user for #
// Create your linear sec
// Print (the # and index)
// Time
// Read sorted file
// Load in array
// Develop Binary Search
// Print index Time.

//Linear Search
// Array = 5000 numbers
// number 235 is there and user wants to find
// go from 0 to 5000

int main(void)
{
    string fileName="random5000.txt";
    FILE *file=(fopen(fileName, "r"));
    if(!file)
    {
        printf("\n Unable to open : %s ", fileName);
        return -1;
    }
      //how many characters per line
    char options[5000][5]; //array to put all the numbers from the file

    for (int i=0; i<5000; i++)
    {
        fscanf(file, "%s", options[i]);
    }
    fclose(file);

    int num = get_int("Number: ");
    int x = 1;
    for (int i = 0; i <= 5000; i++)
    {

        if (atoi(options[i]) == num)
        {
            printf("Number %s is in index %i \n", options[i], i);
            break;
        }

    }



//Binary Search
//In binary search, input data need to be in sorted order.
//It is also called a half-interval search.
//The time complexity of binary search O(log n).
//Only single single-dimensional array is used.
//Binary search performs ordering comparisons

//worked with Emrick


    fileName="sorted5000.txt";
    FILE *file2=(fopen(fileName, "r"));
    if(!file2)
    {
        printf("\n Unable to open : %s ", fileName);
        return -1;
    }
      //how many characters per line
    char options[5000][5]; //array to put all the numbers from the file

    for (int i=0; i<5000; i++)
    {
        fscanf(file2, "%s", options[i]);
    }
    fclose(file2);

    int num = get_int("Number: ");
    int lowest=0;
    int highest=4999;

    while (lowest <= highest)
    {
        int midnum= (lowest+highest)/2; //find middle number

        if (atoi(options[midnum]) == num)
        {
            printf("Number %s is in index %i \n", options[midnum], midnum);
            return 0;
        }
        else if (atoi(options[midnum]) < num)
        {
            lowest = midnum + 1;
        }
        else if (atoi(options[midnum]) > num)
        {
            highest = midnum - 1;
        }
    }




//Selection Sort
//Find the smallest number and swap it with the first number.
    //For loop to find minimum

//Find the second smallest number and swap it with the second number.
//Continue until array is sorted

    fileName="random5000.txt";
    FILE *file3=(fopen(fileName, "r"));
    if(!file3)
    {
        printf("\n Unable to open : %s ", fileName);
        return -1;
    }
    char line[4];  //how many characters per line
    char options[5000][4]; //array to put all the numbers from the file

    for (int i=0; i<5000; i++)
    {
        fscanf(file3, "%s", options[i]);
    }
    fclose(file3);

    int min=5000;
    int idx=0;

    for (int i = 0; i< 5000-1; i++) //is to sort the whole array
    {
        int min = i;
        for (int j = j+1; j < 5000; j++) //is to find the new minimum
        {
            if (options[j] < options[min])
            {
                min = j;
            }

        }
        if (min != i)
        {
        int temp = options[i];
        options[i]=options(min);
        options[min]=temp;
        }

}
    printf("Selection Sort Array:\n");
    for (int i = 0; i < 5000; i++) {
        printf("%d ", options[i]);
    }
    printf("\n");

    return 0;
}
