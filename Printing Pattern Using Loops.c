#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b) {
    return a>b ? a : b;
}

int main() 
{

    int n;
    scanf("%d", &n);
      // Complete the code to print the pattern.
    for (int x = 0; x < (2*n - 1); x++) {
        for (int y = 0; y < (2*n - 1); y++) {
            /**
            * Each axis is the abs of the rect
            * given by f(x)=n-1-x from 0 to 2n-1,
            * then lifted by 1.
            * To draw the square we print the max
            * value between the two axis in that
            * coordinate.
            */ 
            int value = max(
                abs(n-x-1)+1, // Value for the x axis
                abs(n-y-1)+1  // Value for the y axis
            );
            printf("%d ", value);
        }
        printf("\n");
    }
    return 0;
}
