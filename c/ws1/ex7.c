#include <stdio.h>

void swap (int *a, int *b);

int main ()
{
    int x = 5, y = 10;

    printf("First is %d, second is %d \n", x,y);

    swap(&x, &y);

    printf("After the interchange first is %d, second is %d \n", x,y);

    return 0;
}



void swap (int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}


