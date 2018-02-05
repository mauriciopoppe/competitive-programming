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
#define SP system("pause")
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 5000000
int p[M+1];
int dp[M+1];
void gen()
{
     for(int i=4;i<=M;i+=2)p[i]+=2;
     for(int i=3;2*i<=M;i+=2) 
        if(!p[i])
        for(int j=2*i;j<=M;j+=i)
           p[j]+=i;
     
     int k=0;
     for(int i=2;i<=M;i++)
     {
         if(p[i]==0 || p[p[i]]==0)dp[i]=++k;
         else dp[i]=k;
     }
     
}

int main()
{
    gen();
    //F(i,25)printf("%d ",p[i]);
    int x,y;
    while(scanf("%d",&x))
    {
         if(!x)break;
         scanf("%d",&y);                
         if(x+y==0)break;   
         printf("%d\n",dp[y]-dp[x-1]);
    }
    return 0;
}
