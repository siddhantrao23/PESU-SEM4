#include <stdlib.h>
#include <stdio.h>
#include "mergeSort.h"

void mergeSortedHalfs(int *a, int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1; 
    int n2 = end - mid; 
    int *L = malloc(sizeof(int)*n1);
    int *R = malloc(sizeof(int)*n2);
    for(i = 0; i < n1; i++) {
        L[i] = a[start + i]; 
    }
    for(j = 0; j < n2; j++) {
        R[j] = a[mid + 1+ j];
    } 
    i = 0;
    j = 0;
    k = start;
    while(i < n1 && j < n2) { 
        if(L[i] <= R[j]) { 
            a[k] = L[i++];
        } 
        else { 
            a[k] = R[j++]; 
        } 
        k++; 
    } 
    while(i < n1) { 
        a[k++] = L[i++]; 
    } 
    while(j < n2) { 
        a[k++] = R[j++]; 
    } 
}

void mergeSort(int *a, int start, int end)
{
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid+1, end);
        mergeSortedHalfs(a, start, mid, end);
    } else {
        return;
    } 
}

void insertionSort(int *a, int start, int end)
{
    for(int i=start; i<=end; ++i) {
        int j = i - 1;
        int ins = a[i];
        while(j >= 0 && a[j] > ins) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] - ins;
    }
}

void selectiveMergeSort(int *a, int start, int end, int parameter)
{
    if(end-start+1 > parameter) {
        mergeSort(a, start, end);
    } else {
        insertionSort(a, start, end);
    }
}
