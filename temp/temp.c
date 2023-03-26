#include <stdio.h>
#include <stdbool.h>

int main() {
	float a = 2.5f, b = 7.5f, c = 5.0f, d = 6.0f;
	printf("%d", c/2+d < a && false || c <= d);
	return 0;
}