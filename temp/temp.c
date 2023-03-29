#include<stdio.h>
int main(void) {
	int fib_numbers[40] = { 1,1 };
	for (int i = 2; i < 40; i++) {
		fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
	}
	for (int j = 0; j < 40; j++) {
		printf("%d\n", fib_numbers[j]);
	}

}
