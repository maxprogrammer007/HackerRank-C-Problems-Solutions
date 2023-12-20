#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b) > 0 ? 1 : 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a) > 0 ? 1 : 0;
}

int get_distinct_chars(const char *s) {
    int chars[127] = {0};
    int cnt = 0;
    while (*s != '\0') {
        if (chars[*s] == 0) {
            chars[*s]++;
            cnt++;
        }
        s++;
    }
    return cnt;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distA = get_distinct_chars(a);
    int distB = get_distinct_chars(b);
    
    if (distA == distB) {
        return lexicographic_sort(a, b);
    } else if (distA > distB) {
        return 1;
    }
    return 0;
}

int sort_by_length(const char* a, const char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    if (lenA == lenB) {
        return lexicographic_sort(a, b);
    } else if (lenA > lenB) {
        return 1;
    }
    return 0;
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b)) {
    for (int i = 1; i < len; i++) {
        char *key = arr[i];
        int j = i - 1;
        while (j >= 0 && cmp_func(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}