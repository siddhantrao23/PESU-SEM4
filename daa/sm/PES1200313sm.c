#include <string.h>

int searchFirstOccurrence(char *pattern, char *text)
{
	int n = strlen(text);
	int m = strlen(pattern);
	int i, j;
	for (i = 0; i <= n-m; ++i) {
		for (j = 0; j < m; j++) {
			if (text[i+j] != pattern[j]) {
				break;
			}
		}
		if (j == m) {
			return i;
		}
	}
	return -1;
}

int searchLastOccurrence(char *pattern, char *text) {
	int n = strlen(text);
	int m = strlen(pattern);
	int i, j;
	for (i = n-m; i >= 0; --i) {
		for (j = 0; j < m; j++) {
			if (text[i+j] != pattern[j]) {
				break;
			}
		}
		if (j == m) {
			return i;
		}
	}
	return -1;
}

int numOccurrences(char *pattern, char *text) {
	int n = strlen(text);
	int m = strlen(pattern);
	int count = 0;
	char *temp = text;
	while (strlen(temp) > 0) {
		int i = searchFirstOccurrence(pattern, temp);
		if (i == -1)
			break;
		temp += i+m;
		count++;
	}
	return count;
}

int longestPrefix(char *pattern, char *text)
{
	int max = 0;
	int n = strlen(text);
	int m = strlen(pattern);
	int i, j;
	for (i = 0; i <= n-m; ++i) {
		int len = 0;
		for (j = 0; j < m; j++) {
			if (text[i+j] != pattern[j]) {
				break;
			}
			len++;
		}
		if (len > max)
			max = len;
	}
	return max;
}

int charactersCompared(char *pattern, char *text)
{
	int n = strlen(text);
	int m = strlen(pattern);
	int count = 0;
	for (int i = 0; i <= n-m; ++i) {
		for (int j = 0; j < m; j++) {
			count++;
			if (text[i+j] != pattern[j]) {
				break;
			}
		}
	}
	return count;
}
