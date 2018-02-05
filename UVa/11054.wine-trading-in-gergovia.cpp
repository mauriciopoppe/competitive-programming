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

int v[100002];
int main()
{
    int t,aux,cr,cl;
    while(scanf("%d",&t) && t)
    {
         int i=0,j=0,k;
         for(int i=0;i<t;++i)
             scanf("%lld",&v[i]);
                                         
         long long m=0;
         for(int i=1;i<t;i++)
         {
              m+=(long long)(abs(v[i-1])); 
              v[i]+=v[i-1];
         }
         
         printf("%lld\n",m);
                         
    }
    return 0;
}
