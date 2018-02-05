#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main()
{
    int a[20000];
    int t,n;
    scanf("%d",&t);
    for(int q=1;q<=t;q++)
    {
         scanf("%d",&n);
         for(int i=0;i<n-1;i++)scanf("%d",&a[i]);          
         
         int x=-1,y=-1,mx=0,sum=0;
         
         for(int i=0,j=0;i<n-1;i++)
         {
             sum+=a[i];
             if(sum>mx)
             {
                 x=j;
                 y=i; 
                 mx=sum;               
             }    
             else if(sum==mx && i-j>y-x)x=j,y=i;
             if(sum<0)j=i+1,sum=0;
         }         
         
         if(mx==0)printf("Route %d has no nice parts\n",q);
         else printf("The nicest part of route %d is between stops %d and %d\n",q,x+1,y+2);
         
    }
    return 0;
}
