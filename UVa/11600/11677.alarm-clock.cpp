#include<stdio.h>
int main()
{
    int x, y, a, b;
    while(scanf("%d%d%d%d", &x, &y, &a, &b) && a + b + x + y != 0)
    {
        int ini = x * 60 + y, end = a * 60 + b;
        if(end < ini) end += 1440;
        printf("%d\n", end - ini);                    
    }
    return 0;
}
