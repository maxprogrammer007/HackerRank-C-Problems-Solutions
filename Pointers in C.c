#include <stdio.h>

void update(int *a,int *b) {
    int x;  //initialize new variable for a
    x = *a;  // Because after "*a = *a + *b" this line "*a" become "*a + *b" but "*b =  *a - *b" this line want "*a" for old value of "*a" 
    *a = *a + *b;
    *b = abs(x - *b);  // "abs" mean absolute value, then "*b" become positive only    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
