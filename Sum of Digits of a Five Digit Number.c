#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,sum;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    while (n > 0){
    int digit = n%10;
    n/=10;
    sum+=digit;
 }
 printf("%d",sum);

    return 0;
}
