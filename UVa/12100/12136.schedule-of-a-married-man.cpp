#include<stdio.h>
int main()
{
    int cas, x1, y1, x2, y2, x3, y3, x4, y4, z;
    scanf("%d", &cas);
    for(z = 1; z <= cas; ++z)
    {
        scanf("%d:%d %d:%d %d:%d %d:%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        printf("Case %d: ", z);
        if(x4 * 60 + y4 < x1 * 60 + y1 || x3 * 60 + y3 > x2 * 60 + y2)
           puts("Hits Meeting");
        else
           puts("Mrs Meeting");
    }
    return 0;
}
