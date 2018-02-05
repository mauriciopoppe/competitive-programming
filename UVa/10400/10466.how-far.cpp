#include <stdio.h>
#include <math.h>
#define PI 2 * acos(0)
double x[51], y[51];
int main()
{
    x[0] = y[0] = 0;
    int n, time, i, cycle;
    double r, angle;
    while(scanf("%d%d", &n, &time) != EOF)
    {
         for(i = 1; i <= n; ++i)
         {
             scanf("%lf%d", &r, &cycle);
             angle = 2.0 * PI / (double) cycle, cycle = time % cycle,
             x[i] = x[i - 1] + r * cos(angle * (double)cycle),
             y[i] = y[i - 1] + r * sin(angle * (double)cycle);
             if(i == 1)
                printf("%.4lf", sqrt(x[i] * x[i] + y[i] * y[i]));
             else
                printf(" %.4lf", sqrt(x[i] * x[i] + y[i] * y[i]));
         }         
         putchar(10);
    }
    return 0;
}
