#include <stdio.h>
 
 
void CopyArray(int *a, int *b, int arr_size);

int main ()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5];
    int n = 5;
    int i;
    
    CopyArray(a, b, n);
    
    printf("original --> copy: \n");
    
    for (i = 0; i < n; i++) {
    printf("%2d           %2d \n", a[i], b[i]);
    } 
    
    return 0;    
}

void CopyArray(int *a, int *b, int arr_size)
{
    int i;
            
    for (i = 0; i < arr_size; i++)
    {
    b[i] = a[i];
    }
}

