#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

       char num[1000];
    scanf("%s",num);   
    // printf("%s",num);
    int arr[10]={0};
    for(int i=0;i<strlen(num);i++){
        if(!isalpha(num[i])){
            arr[num[i]-48]++;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
    
    return 0;
}
