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

int a[20005];
int main()
{
    int t,n;
    scanf("%d",&t);
    ++t;
    while(--t)
    {
         scanf("%d",&n);
         for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
         
         sort(a,a+n);
         
         int t=0;
         
         n-=3;
         while(n>=0)
         {
              t+=a[n];
              n-=3;       
         }
         printf("%d\n",t);
    }
    return 0;
}
