#include<stdio.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

int main()
{
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    int lx, ly, ux, uy;
    int n, area = 100 * 100;
    int ss, s, ns, z;
    int cas;
    scanf("%d", &cas);
    for(z = 0; z < cas; ++z)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
        lx = max(x1, x3);
        ly = max(y1, y3);
        ux = min(x2, x4);
        uy = min(y2, y4);        
        if(ux > lx && uy > ly)
           ss = (ux - lx) * (uy - ly);
        else
           ss = 0;
        
        s = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3) - 2 * ss;
        ns = area - s - ss;
        printf("Night %d: %d %d %d\n", z + 1, ss, s, ns);
    }
    return 0;
}
