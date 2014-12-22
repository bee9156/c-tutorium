#include <stdio.h>

int f(int a, int b)
{
    printf("a: %d, b: %d\n", a, b);
    if (b == 0) return a;
    return f(b, a % b);
}

int main(void)
{
    printf("%d\n", f(342, 162));
    return 0;
}
