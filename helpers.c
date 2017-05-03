/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n<=0)
    {
        return false;
    }    
    int start=0; 
    int end = n-1;
    int mid = (start+end)/2;
    do
    {
        if(values[mid]==value)
        {
            return true;
        }
        //if key element is in left half side
        else if(values[mid]>value)
        {
            end=mid-1;
        }
        //if key element is in right half side
        else
        {
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    while(start<=end);
    return false;
}

/**
 * Sorts array of n values.
 */


void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm

    int min,j,i;
    for(i=0; i<n-1; i++)
    {
        min=i;
        //finding smallest element
        for(j=i+1; j<n; j++)
        {
            if(values[j]<values[min])
            {
                min=j;
            }
        }
        //swaping the elements
        if(min!=i)
        {
            int temp=values[min];
            values[min]=values[i];
            values[i]=temp;
        }
    }
    return;
}

