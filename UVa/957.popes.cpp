#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
int a[100002];

int main()
{
    int year,n;
    while(scanf("%d",&year)!=EOF)
    {
         scanf("%d",&n);
         for(int i=0;i<n;i++)
              scanf("%d",&a[i]);
         
         int i,j,x=-1,y=-1,c=0,t,mx=0;
         for(int i=0;i<n;i++)
         {
              j=i;
              c=0;
              t=a[i]+year;
              while(a[j]<t && j<n)        
              {
                  c++;
                  j++;                      
              }
              
              if(c>mx)
              {
                  mx=c;
                  x=i;
                  y=j-1;        
              }                 
         }
         
         printf("%d %d %d\n",mx,a[x],a[y]);                       
    }
    return 0;
}
