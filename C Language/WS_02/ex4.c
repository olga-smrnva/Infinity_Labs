#include <stdio.h>

void SwapTwoPointers(size_t **ptr_a, size_t **ptr_b);
void SwapTwoSize_t(size_t *a, size_t *b);

int main ()
{
    size_t a = 5, b = 10;
    size_t *ptr_a = &a;
    size_t *ptr_b = &b;
    size_t add_a, add_b;

    printf("First pointer is %lu, second is %lu \n", (long unsigned int) ptr_a, (long unsigned int) ptr_b);

    SwapTwoPointers(&ptr_a, &ptr_b);

    printf("After the interchange first is %lu, second is %lu \n", (long unsigned int) ptr_a, (long unsigned int) ptr_b);
    
       
    add_a = (size_t) ptr_a;
    add_b = (size_t) ptr_b;
    
    printf("\n");
    printf("First pointer is %lu, second is %lu \n", (long unsigned int) ptr_a, (long unsigned int) ptr_b);

    SwapTwoSize_t(&add_a, &add_b);
    
    ptr_a = (size_t *) add_a;
    ptr_b = (size_t *) add_b;

    printf("After the interchange first is %lu, second is %lu \n", (long unsigned int) ptr_a, (long unsigned int) ptr_b);
    
    printf("\n");
    printf("First is %lu, second is %lu \n", (long unsigned int) a,(long unsigned int) b);

    SwapTwoSize_t(&a, &b);

    printf("After the interchange first is %lu, second is %lu \n", (long unsigned int) a,(long unsigned int) b);

   return 0;
}



void SwapTwoPointers(size_t **ptr_a, size_t **ptr_b)
{
    size_t *tmp;

    tmp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = tmp;
}

void SwapTwoSize_t(size_t *a, size_t *b)
{
    size_t tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
