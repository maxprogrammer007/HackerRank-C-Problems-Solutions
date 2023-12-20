#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i, j=0, temp;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) 
    {
        scanf("%d", arr + i);
    }
    for(i = 0; i < num; i++)
    {
        j=((num-1)-i);
        if((i>j)||(j==i))
        break;
        else 
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;}
    } 
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
