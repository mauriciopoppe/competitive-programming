#include<stdio.h>
#include<algorithm>
#include<cstdlib>
int main()
{
    int n,s,d,a,b;
    scanf("%d",&n);
    while(n--)
    {
       scanf("%d%d",&s,&d);
       b=(s-d)/2;
       a=s-b;
       if(a+b!=s || abs(a-b)!=d || a<0 || b<0)printf("impossible\n");     
       else printf("%d %d\n",a,b);      
    }
    return 0;
}
