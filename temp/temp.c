#include<stdio.h>
int main()
{
	char j;
	printf("Enter an uppercase letter:\n");
	scanf("%c", &j);
	while (i <= j)
	{
		for (; j <= i; j++) /*两个循环嵌套*/
		{
			printf("%c", j);
		}
		printf("\n");
		i++;
	}
	printf("%c", j);
	return 0;
}
