/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int a, int mass[], int n)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < mass[middle])
            high = middle - 1;
        else if (a > mass[middle])
            low = middle + 1;
        else
            return true;
    }
    return false;
}

void sort(int values[], int n)
{
    //int sorted[n];
    for(int i = 1;i<n;i++){
    for(int j = 1;j<n;j++){
        if(values[j-1]>values[j]){int c = values[j-1]; values[j-1]=values[j]; values[j] = c;}
    }
    }
    //values = sorted;




    return;
}
