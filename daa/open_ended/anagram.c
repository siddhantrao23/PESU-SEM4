#include <stdio.h>
#include <string.h>

#define SIZE_OF_DICT 7
/*  Design an efficient algorithm to find all anagrams in a dictionary file 
 *  EX:
 *  1)ate = tea = eat
 *  2)conversation = voice rants on
 */

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void anagram(char *a, int l, int r, char dict[][100]) 
{ 
    int i; 
    if (l == r) {
        for(int i=0; i<SIZE_OF_DICT; ++i) {
            if(strcmp(a, dict[i]) == 0) {
                printf("%s\n", a); 
            }
        }
    }
    else
    { 
        for (i = l; i <= r; i++) 
        { 
            swap((a+l), (a+i)); 
            anagram(a, l+1, r, dict); 
            swap((a+l), (a+i)); //backtrack 
        } 
    } 
} 

int main() 
{ 
    char str[] = "ate"; 
    char dict[7][100]={"ate","eat","pea","dog","god","cat","act"};
    int n = strlen(str); 
    anagram(str, 0, n-1, dict); 
    return 0; 
}

