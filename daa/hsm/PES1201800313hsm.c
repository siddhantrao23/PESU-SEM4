#include"horspool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *buildShiftTable(char *pattern)
{
    int* table = (int*)malloc(sizeof(int)*256);
    int m = strlen(pattern);
    for(int j = 0; j < 256; j++)
        table[j] = m;
    for(int i = 0; i < m-1; i++)
        table[(int)(pattern[i])] = m-1-i;
    return table;
}


Result *horspoolStringMatch(char *pattern, char *text)
{
    int *shift = buildShiftTable(pattern);
    int m = strlen(pattern);
    int n = strlen(text);
    int k;
    Result* r = (Result*)malloc(sizeof(Result));
    r->firstOccurrence = -1;
    r->lastOccurrence = -1;
    r->numOccurrences = 0;
    r->charactersCompared = 0;
    int i = m-1;
    while(i <= n-1)
    {
        k = 0;
        while(m-k-1 >= 0 && i-k >= 0 && pattern[m-1-k] == text[i-k]) {
            k++;
        }
        if(k == m)
        {
            if(r->numOccurrences == 0){
                r->firstOccurrence = i-m+1;
            }
            r->lastOccurrence = i-m+1;
            r->numOccurrences += 1;
            r->charactersCompared += m;
            i = i+m;
        }
        else
        {
            r->charactersCompared += k+1;
            i = i+shift[(int)text[i]];
        }
    }
    r->charactersCompared += 1;
    return r;
}
