// Merges two sorted halfs of an array into a single sorted array
#include<stdlib.h>
#include"mergeSort.h"
void mergeSortedHalfs(int *a, int start, int mid, int end)
{
    int i,j,k;
	int n1 =mid-start + 1; 
    int n2 =end-mid; 
    int *L=malloc(sizeof(int)*n1);
    int *R=malloc(sizeof(int)*n2);
    for (i = 0; i < n1; i++) 
	{
        	L[i] = a[start + i]; 
    }
	for (j = 0; j < n2; j++) 
    {
		R[j] = a[mid + 1+ j];
	} 
	i=0;
	j=0;
	k=start;
	while (i < n1 && j < n2) 
    { 
        	if (L[i] <= R[j]) 
        	{ 
            		a[k] = L[i]; 
            		i++; 
        	} 
        	else
        	{ 
            		a[k] = R[j]; 
            		j++; 
        	} 
        	k++; 
    } 
  	while (i < n1) 
    { 
        	a[k] = L[i]; 
        	i++; 
        	k++; 
    } 
  	while (j < n2) 
    { 
        	a[k] = R[j]; 
        	j++; 
        	k++; 
    } 
}

// Implement merge sort using the mergeSortedHalfs() declared above
// start is the index of the first element of the array
// end is the index of the last element of the array
void mergeSort(int *a, int start, int end)
{
    if(start<end)
    {
        int mid = (start+end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        mergeSortedHalfs(a,start,mid,end);
    }
    return;
}

// Implement insertion sort
// n - number of elements in the array
void insertionSort(int *a, int start, int end)
{
    int i, key, j; 
    	int n=end-start+1;
    	for (i = 1; i < n; i++) 
	{ 
        	key = a[i]; 
        	j = i - 1; 
		while (j >= 0 && a[j] > key) 
		{ 
            		a[j + 1] = a[j]; 
            		j = j - 1; 
        	} 
        	a[j + 1] = key; 
    	} 
}

// Implement a function which applies merge sort only if
// size of the array is larger than that of parameter
// if not apply insertion sort.
// Use mergeSortedHalfs() and insertionSort() declared above to do the same.
void selectiveMergeSort(int *a, int start, int end, int parameter)
{
        int n=end-start+1;
    	if(parameter>n)
    	{
        	insertionSort(a,start,end);
   	    }
    	else
    	{
        	mergeSort(a,start,end);
    	}
}
