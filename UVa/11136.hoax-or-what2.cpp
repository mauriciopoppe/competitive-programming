#include<iostream>
using namespace std;
static int *v=new int[1000010];
int main()
{
    int n,x,a;
    while(scanf("%d",&n) && n)
    {
         fill(v,v+1000005,0);                         
         long long t=0;
         for(int j=0;j<n;j++)
         {        
             scanf("%d",&x);
             for(int i=0;i<x;i++)
             {
                 scanf("%d",&a);
                 v[a]++;
             }
             
             //printf("%d\n",v[1000000]);
             int x=0,y=0;
             for(x=1000000;x>=1;x--)
                if(v[x])break;
             for(y=1;y<=1000000;y++)
                if(v[y])break;
             t+=x-y;             
             v[x]--;
             v[y]--;
             //printf("%d\n",v[1000000]);
             
         }             
         printf("%lld\n",t);
    }
    return 0;
}
