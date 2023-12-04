#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


#define SIZE1 5000
#define SIZE2 10000
#define SIZE3 50000

void Menu();

int main(void)
{
    int choice;

    do {
        Menu();
        choice = get_int("Please enter your choice 1-5: ");

        switch (choice) {
            case 1: {
//Linear Search
// Array = 5000 numbers
// number 235 is there and user wants to find
// go from 0 to 5000
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
                break;
            }

            case 2: {
                //Binary Search
//In binary search, input data need to be in sorted order.
//It is also called a half-interval search.
//The time complexity of binary search O(log n).
//Only single single-dimensional array is used.
//Binary search performs ordering comparisons

//worked with Emrick


        string fileName="sorted5000.txt";
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
                break;
            }

            case 3: {
//Selection Sort
//Find the smallest number and swap it with the first number.
    //For loop to find minimum

//Find the second smallest number and swap it with the second number.
//Continue until array is sorted

        string fileName="random5000.txt";
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
            int temp = atoi(options[i]);
            options[i]=options(min);
            options[min]=temp;
            }

    }
        printf("Selection Sort Array:\n");
        for (int i = 0; i < 5000; i++) {
            printf("%d ", options[i]);
        }
        printf("\n");
                break;
            }

            case 4: {
//Bubble Sort

                fileName="random5000.txt";
            FILE *file4=(fopen(fileName, "r"));
            if(!file4)
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
            fclose(file4);

            for (int i = 0; i < 5000 - 1; i++) {
                for (int j = 0; j < 5000 - i - 1; j++) {
                    if (options[j]> options[j+1]){

                        int temp = options[j];
                        options[j] = options[j+1]
                        options[j+1] = temp;
                    }

            printf("Bubble Sort Array:\n");
            for (int i = 0; i < 5000; i++) {
                printf("%d ", options[i]);
            }
            printf("\n");
            break;
            }

        case 5:
        printf("Exiting...\n");
                break;
            }

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void Menu()
{
    // make a menu
    printf("=====================================\n");
    printf("#               MENU                #\n");
    printf("#   1) Do Linear Search?            #\n");
    printf("#   2) Do Binary Search?            #\n");
    printf("#   3) Do Selection Sort?           #\n");
    printf("#   4) Do Bubble Sort?              #\n");
    printf("#   5) Exit                         #\n");
    printf("=====================================\n");
}



