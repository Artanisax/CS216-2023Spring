#include <stdio.h>

#define MIN(x,y) (x) < (y) ? (x) : (y)

int main()
{
	int i = 10, j = 15;
	printf("%d", 10*MIN(i, j));
	return 0;
}