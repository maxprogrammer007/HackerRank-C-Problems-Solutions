#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    char s[100];                //Initializing space for character s
    printf("Hello, World!\n");   //Already given input
    gets(s);                                  //Asking user to enter string
    printf("%s",s);                       //printing the asked string
    return 0;
}
