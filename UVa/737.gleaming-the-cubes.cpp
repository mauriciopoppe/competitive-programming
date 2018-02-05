#include<stdio.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main()
{
    int cx1, cy1, cz1, cx2, cy2, cz2;
    int x1, y1, z1;
    int lx, ly, lz, ux, uy, uz;
    int side;
    int cas;
    int i;
    while(scanf("%d", &cas) && cas)
    {
        int f = 1;
        for(i = 0; i < cas; ++i)
        {
            scanf("%d%d%d%d", &x1, &y1, &z1, &side);
            if(!f)continue;
            if(i == 0)
                cx1 = x1, cx2 = x1 + side, cy1 = y1, cy2 = y1 + side, cz1 = z1, cz2 = z1 + side;    
            else
            {
                if((lx = max(cx1, x1)) >= (ux = min(cx2, x1 + side)) ||
                   (ly = max(cy1, y1)) >= (uy = min(cy2, y1 + side)) ||
                   (lz = max(cz1, z1)) >= (uz = min(cz2, z1 + side)))
                    f = 0;
                cx1 = lx, cx2 = ux, cy1 = ly, cy2 = uy, cz1 = lz, cz2 = uz;
            }
        }
        if(f)printf("%d\n", (cx2 - cx1) * (cy2 - cy1) * (cz2 - cz1));
        else puts("0");
    }
    return 0;
}
