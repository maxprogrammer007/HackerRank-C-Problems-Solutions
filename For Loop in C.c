#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
      for(int n = a; n<=b; n++) {
          if(1<=n && n<=9){
              if(n==1){
                  printf("one\n");
              }
              else if(n==2){
                  printf("two\n");
              }
              else if(n==3){
                  printf("three\n");
              }
              else if(n==4){
                  printf("four\n");
              }
              else if(n==5){
                  printf("five\n");
              }
              else if(n==6){
                  printf("six\n");
              }
              else if(n==7){
                  printf("seven\n");
              }
              else if(n==8){
                  printf("eight\n");     
              }
              else if(n==9){
                  printf("nine\n");
              }
           }
           else if(n>9 && n%2==0){
               printf("even\n");
            }
           else if(n>9 && n%2!=0){
               printf("odd\n");
           }
         }
       return 0;
}
