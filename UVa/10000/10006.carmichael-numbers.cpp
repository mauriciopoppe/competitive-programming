#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
#define M 70000
typedef long long LL;

int dp[M];
bitset<M> b;

LL pow2(LL a)
{
    return a*a;
}

void gen()
{
     b[0]=b[1]=1;
     for(int i=4;i<M;i+=2)b[i]=1;
     for(int i=3;i*i<=M;i+=2)
       if(!b[i])
         for(int j=i*i;j<=M;j+=2*i)
           b[j]=1;            
}

LL bigmod(LL b, LL p, LL m)
{
    if(p==0)return 1;
    else if(!(p&1))return pow2(bigmod(b,p/2,m))%m;
    else return ((b%m)*(bigmod(b,p-1,m)))%m;
}

int main()
{
    gen();
    //FOR(i,1720,1730)if(!b[i])printf("%d ",i);
    int n;
    while(cin>>n && n)
    {
         if(!b[n])printf("%d is normal.\n",n);
         else
         {
             //printf("here");
             if(!dp[n])
             {
                 int i=0;
                 for(i=2;i<n;i++)
                 {
                    //printf("%d %lld\n",i,bigmod((LL)i,(LL)n,(LL)n));                
                    if(bigmod((LL)i,(LL)n,(LL)n)!=(LL)i)break;
                 }
                 if(i==n)dp[n]=2;
                 else dp[n]=1;
             }
             if(dp[n]==1)printf("%d is normal.\n",n);
             else printf("The number %d is a Carmichael number.\n",n);
         }
    }
    return 0;
}
