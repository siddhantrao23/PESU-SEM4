#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 
#define n 4
 
// A min heap node
struct MinHeapNode
{
    int element; // The element to be stored
    int i; // index of the array from which the element is taken
    int j; // index of the next element to be picked from array
};
typedef struct MinHeapNode MinHeapNode;
 
// Prototype of a utility function to swap two min heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);
 
MinHeapNode *harr; // pointer to array of elements in heap

int heap_size; // size of min heap

    // Constructor: creates a min heap of given size
void MinHeap(MinHeapNode a[], int size);
 
    // to heapify a subtree with root at given index
void MinHeapify(int );
 
    // to get index of left child of node at index i
int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
int right(int i) { return (2*i + 2); }
 
    // to get the root
MinHeapNode getMin() { return harr[0]; }
 
    // to replace root with new node x and heapify() new root
    void replaceMin(MinHeapNode x) { harr[0] = x;  MinHeapify(0); }

 
// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
int *mergeKArrays(int arr[][n], int k)
{
    int *output =(int*)malloc(n*k*(sizeof(int)));  // To store output array
 
    // Create a min heap with k heap nodes.  Every heap node
    // has first element of an array
    MinHeapNode *harr = (MinHeapNode*)malloc(k*(sizeof(MinHeap)));
    for (int i = 0; i < k; i++)
    {
        harr[i].element = arr[i][0]; // Store the first element
        harr[i].i = i;  
        harr[i].j = 1;  
    }
    MinHeap(harr, k); // Create the heap
 
   
    for (int count = 0; count < n*k; count++)
    {
     
        MinHeapNode root = getMin();
        output[count] = root.element;
 
     
        if (root.j < n)
        {
            root.element = arr[root.i][root.j];
            root.j += 1;
        }
       
        else root.element =  INT_MAX;
       
        replaceMin(root);
    }
 
    return output;
}
 

void MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
 
void MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 

void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;  *x = *y;  *y = temp;
}
 



void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
       printf("%d\n",arr[i]);
}
 

int main()
{
   
    int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);
 
    int *output = mergeKArrays(arr, k);
 
   printf("The merged array is \n");
    printArray(output, n*k);
 
    return 0;
} 
