#include <stdio.h>

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        puts(n%6 ? "Alice" : "Bob");
    }
    return 0;
}