#include <stdio.h>

volatile int a[5][5];

int main()
{
    volatile int *p = &a[0][0];
    volatile int **pp = &p;
    printf("%zu\n%zu\n%zu", a, p, pp);
    printf("\n%zu\n%zu\n%zu", a+1, a[1], &a[1][0]);
    return 0;
}