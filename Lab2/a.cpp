#include <stdio.h>

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf(n%6 ? "Alice" : "Bob");
        if (t) putchar('\n');
    }
    return 0;
}