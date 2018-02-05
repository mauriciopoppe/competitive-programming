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
#define M 1000000
bitset<M+1> b;
int p[M+1],dp[M+1],c;

void gen()
{
     for(int i=4;i<=M;i+=2)b[i]=1;
     for(int i=3;i*i<=M;i+=2)
        if(!b[i])
          for(int j=i*i;j<=M;j+=2*i)
             b[j]=1;    
     c=0;
     FOR(i,2,M+1)if(!b[i])p[c++]=i;
     
}
int main()
{
    gen();
    int n;
    while(cin>>n && n)
    {
         int k=n;        
         if(!dp[n])
         {        
             int total=0;         
             for(int i=0;p[i]*p[i]<=n;i++)
             {
                  if(n%p[i]==0)
                  {   
                      ++total;
                      while(n%p[i]==0)n/=p[i];
                  }
             }
             if(n>1)++total;
             dp[k]=total;
         }        
         printf("%d : %d\n",k,dp[k]);
    }
    return 0;
}
