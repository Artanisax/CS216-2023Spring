#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *ptr1 = arr;
    int *ptr2 = arr + 2;

    printf("%d ", *ptr1);
    printf("%d ", *ptr2);
    printf("%d ", ptr2 - ptr1);
    printf("%d ", *ptr1++);
    printf("%d ", *ptr2--);
    printf("%d", *ptr1);
    return 0;
}