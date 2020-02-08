#include "session5_sort.h"


int binarySearch(Record *a, Record item, int low, int high)
{
    if (high <= low)
        return (item.serialnumber > a[low].serialnumber)?  (low + 1): low;

    int mid = (low + high)/2;

    if(item.serialnumber == a[mid].serialnumber)
        return mid+1;

  //  if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}

long int InsertionSort(Record* A, int n)
{
  long int count = 0;
  for(int i = 0; i < n; i++)
  {
    int j = i - 1;
    Record temp = A[i];
    while(j >= 0 && A[j].serialnumber > temp.serialnumber)
    {
      count++;
      A[j + 1] = A[j];
      j--;
    }
    if(j!=-1)
    {
      count++;
    }
    A[j + 1] = temp;
  }
  return count;
}
// Function to sort an array a[] of size 'n'
long int BinaryInsertionSort(Record* a, int n)
{
    int i, loc, j, k;
    long int count = 0;
    Record selected;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);

        // Move all elements after location to create space
        while (j > loc)
        {
            a[j+1] = a[j];
            j--;
        }
        if(j!=-1)
        {
          count++;
        }
        a[j+1] = selected;
    }
    return count;
}

long int BubbleSort(Record* A, int n)
{
    long int count = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int noSwaps = 0;
        for (int j = 0; j < n - 1 - i ; j++)
        {
            count++;
            if (A[j + 1].serialnumber < A[j].serialnumber )
            {

                Record temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                noSwaps = 1;
            }
        }
        if(noSwaps == 0)
            return count;
    }
    return count;
}

long int SelectionSort(Record* A, int n)
{
    long int count = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            count++;
            if(A[j].serialnumber < A[min].serialnumber)
            {
                min = j;
            }
        }
        if(min != i)
        {
            Record temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
    return count;
}
