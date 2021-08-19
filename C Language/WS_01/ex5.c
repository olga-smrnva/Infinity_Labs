#include <stdio.h>
#include <stdlib.h>

double power(int n)
{
    double result = 1;
    float x = 10;
    int i;
        
    if (n<0) {
        n = -n;
        x = 1/x;
    }
    
    for (i=0; i<n; i++)
        result *= x;
   
    return result;
}


int main()
{
   int n;

   printf("Enter a number \n");
   scanf("%d", &n);
   
     printf("10 powered to %d is %f\n", n, power(n));
     
   return 0;
}

