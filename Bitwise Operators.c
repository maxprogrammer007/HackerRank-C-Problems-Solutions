#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) {
    int maxAnd = 0, maxOr = 0, maxXor = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((j & i) > maxAnd && (j & i) < k) {
                maxAnd = j & i;
            }
            if ((j | i) > maxOr && (j | i ) < k) {
                maxOr = j | i;
            }                 
            if ((j ^ i) > maxXor && (j ^ i) < k) {
                maxXor = j ^i;
            }  
        }
    }
    printf("%d\n%d\n%d\n", maxAnd, maxOr, maxXor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
