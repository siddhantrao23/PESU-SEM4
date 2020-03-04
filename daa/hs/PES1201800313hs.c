#include "heapSort.h"

Heap buildMaxHeap(int *const a, int n)
{
    Heap h;
    h.a = a;
    h.size = n;
    for(int i=(n/2-1); i>=0; --i) {
        maxHeapify(h, i);
    }
    return h;
}

void maxHeapify(Heap h, int idx)
{
    int x, largest, j, i;
    largest = idx;
    j = 2 * idx + 2;
    i = 2 * idx + 1;
    if(i < h.size && h.a[i] > h.a[largest])
        largest = i;
    if(j < h.size && h.a[j] > h.a[largest])
        largest = j;
    if(h.a[largest] > h.a[idx])
    {
        x = h.a[largest];
        h.a[largest] = h.a[idx];
        h.a[idx] = x;    
        maxHeapify(h, largest);
    }
}

void heapSort(int *const a, int n)
{
    Heap h = buildMaxHeap(a, n);
    for(int i=n-1; i>=0; --i) {
        int largest = h.a[0];
        h.a[0] = h.a[i];
        h.a[i] = largest;
        h.size -= 1;
        maxHeapify(h, 0);
    }
}
