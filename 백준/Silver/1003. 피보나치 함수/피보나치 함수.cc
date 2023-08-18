#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a, n, f[41], f0[41];
    f[0] = 0;
    f[1] = 1;
    f0[0] = 1;
    f0[1] = 0;
    for (int i = 2; i < 41; i++)
    {
        f[i] = f[i - 2] + f[i - 1];
        f0[i] = f0[i - 2] + f0[i - 1];
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        printf("%d %d\n", f0[a], f[a]);
    }
}