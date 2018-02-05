#include<stdio.h>

int main()
{
    int t,n,k,p,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
         scanf("%d%d%d",&n,&k,&p);
         int r=((k+p)%n==0)?n:(k+p)%n;     
         printf("Case %d: %d\n",i,r);
    }    
    return 0;
}
