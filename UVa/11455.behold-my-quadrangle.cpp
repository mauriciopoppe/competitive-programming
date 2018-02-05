#include<stdio.h>
#include<string.h>
int main()
{
    int cas, i;
    int n;
    scanf("%d", &cas);
    int v[5];
    while(cas--)
    {
         for(i = 0; i < 4; ++i)
         {
             scanf("%d", &v[i]);
             int k = v[i], j;
             for(j = i - 1; j >= 0 && v[j] > k; v[j + 1] = v[j], --j);
             v[j + 1] = k;
         }
         if(v[0] == v[1] && v[1] == v[2] && v[2] == v[3])puts("square");
         else if(v[0] == v[1] && v[2] == v[3] && v[0] != v[2])puts("rectangle");
         else if(v[0] + v[1] + v[2] > v[3])puts("quadrangle");
         else puts("banana");
    }
    return 0;
}
