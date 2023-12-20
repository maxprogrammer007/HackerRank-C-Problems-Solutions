#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
float calcularArea(triangle triangulo)
{
    int a=triangulo.a,b=triangulo.b,c=triangulo.c;
    float p= (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void sort_by_area(triangle* tr, int n) {
    triangle temp;
    int j;
    for (int k = n/2; k>0; k=k/2) 
    {
        for (int i=k; i<n; i++) 
        {
            temp=tr[i];
            
            for (j=i; j>=k && calcularArea(tr[j-k])>calcularArea(temp);j-=k)
            {
                tr[j]=tr[j-k];
            }
            tr[j]=temp;
            
        }
    }
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}