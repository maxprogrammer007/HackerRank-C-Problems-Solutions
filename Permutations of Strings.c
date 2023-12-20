#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char** array, int firstIndex, int secondIndex) {
    char* temp;
    temp = calloc(11, sizeof(char));
    strcpy(temp, array[firstIndex]);
    strcpy(array[firstIndex], array[secondIndex]);
    strcpy(array[secondIndex], temp);
    free(temp);
}

void reverse(char** array, int substringIndex, int n)
{
    while (substringIndex < n)
    {
        swap(array, substringIndex, n);
        substringIndex++;
        n--;
    }
}

int next_permutation(int n, char **s)
{
    int i = n - 2, q = 0, smallest = 0;
    while(i >= 0) {
        if (strcmp(s[i], s[i + 1]) < 0) {
            smallest = i + 1;
            for (q = smallest; q < n; q++) {
                if (strcmp(s[q], s[i]) > 0 && strcmp(s[q], s[smallest]) <= 0) {
                    smallest = q;
                }
            }
            swap(s, i, smallest);
            reverse(s, i + 1, n - 1);
            return 1;
        }
        i--;
    }
    return 0;
}



int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}