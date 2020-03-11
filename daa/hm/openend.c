/*Design an efficient algorithm for finding all sets of anagrams in a dictionary file
eat- ate, eta,tea....*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
We can implement the search using tries.
To get more efficient search.
*/
typedef struct Trie
{
	struct Trie* child[26];
	int eow;
}trie;
char word[100];
int length;
trie* getNode()
{
	trie* node=(trie*)malloc(sizeof(trie));
	for(int i=0;i<26;i++)
		node->child[i]=NULL;
	node->eow=0;
	return node;
}
void create(trie *root,char key[])
{
	int i=0,x;
	trie *cur=root;
	while(key[i]!='\0')
	{
		x=key[i]-'a';
		if(cur->child[x]==NULL)
		{
			cur->child[x]=getNode();
		}
		cur=cur->child[x];
		i++;
	}
	cur->eow=1;
}
int sr_word(trie *root,char key[])
{
	trie *cur;
    int i,index;
    cur=root;
    for(i=0;key[i]!='\0';i++)
    {
        index=key[i]-'a';
        if(cur->child[index]==NULL)
            return 0;
        cur=cur->child[index];
    }
    if(cur->eow==1)
        return 1;
    return 0;
}
int get_next_permutation(char *permutation, int n) {
	int i, j, k;
	int temp_int, swaps;

	//find i
	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	swaps = (n-1-i)/2;
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}
void anagram(char* text)
{
    
}
