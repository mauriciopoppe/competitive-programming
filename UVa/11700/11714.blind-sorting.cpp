#include<stdio.h>
#include<math.h>
int main()
{
    double n;
    while(scanf("%lf", &n) != EOF)
       printf("%.0lf\n", n - 1 + (int)log2(n - 1));
    return 0;
}
