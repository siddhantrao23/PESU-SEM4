#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "session5_sort.h"

double time_elapsed(struct timespec start, struct timespec end);

double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}
int main()
{

    int num;
    scanf("%d",&num);
    Record Insert[num];
    Record Bubble[num];
    Record Select[num];
    for(int i=0;i<num;i++)
    {
        scanf("%ld",&Insert[i].serialnumber);
        scanf("%d",&Insert[i].score);
        Bubble[i] = Insert[i];
        Select[i] = Insert[i];
    }

    struct timespec start, end; //timestamps

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    long int result = InsertionSort(Insert,num);
    clock_gettime(CLOCK_REALTIME, &end); //End timestamp
    printf("Insertion Sort : %ld %lf\n",result,time_elapsed(start, end));

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    result = BubbleSort(Bubble,num);
    clock_gettime(CLOCK_REALTIME, &end); //End timestamp
    printf("Bubble Sort : %ld %lf\n",result,time_elapsed(start, end));

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    result = SelectionSort(Select,num);
    clock_gettime(CLOCK_REALTIME, &end); //End timestamp
    printf("Selection Sort : %ld %lf\n",result,time_elapsed(start, end));

}
