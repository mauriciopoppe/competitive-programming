#include<stdio.h>
#include<stdlib.h>

int color[2][1000000];
int size[2], move[2];

int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int cas, n, k, i;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        size[0] = size[1] = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &k);
            if(k < 0) color[0][size[0]++] = -k;
            else color[1][size[1]++] = k;
        }
        qsort(color[0], size[0], sizeof(int), cmp);
        qsort(color[1], size[1], sizeof(int), cmp);
        
        if(!size[0] || !size[1])
        {
            printf("%d\n", (size[1] || size[0]) ? 1 : 0);
            continue;   
        }
        move[0] = move[1] = 0;
        int f = !(color[0][0] < color[1][0]);        
        int c = 1, last = color[f][0];
        move[f]++;
        f = !f;
        while(1)
        {
            while(move[f] < size[f] && color[f][move[f]] < last)
               ++move[f];
            if(move[f] == size[f])
               break; 
            ++c;
            last = color[f][move[f]];
            f = !f;
        }
        printf("%d\n", c);
    }
    return 0;
}
