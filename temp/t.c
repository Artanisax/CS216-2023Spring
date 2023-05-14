#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

void swap(char *a, char *b) {
	char temp[100];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

int main() {
	char a[5][100];
	char b[10];
	puts("What are your strings?");

	for (int j = 0; j < 5; j++)
		scanf("%s", a[j]);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4  ; j++)
			if (strlen(a[j]) > strlen(a[j+1]))
				swap(a[j], a[j + 1]);
	for (int j = 0; j < 5; j++) {
		printf("%s ", a[j]);
	}

	for (int i = 0; i < 5; i++) {
		b[i] = a[i][2];
	}
	printf("\n%s", b);
	return 0;
}
