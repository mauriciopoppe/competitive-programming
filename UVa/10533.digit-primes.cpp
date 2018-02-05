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
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 1000001
bitset<M+1> b;
int dp[M+5];
void gen()
{
     for(int i=4;i<M;i+=2)b[i]=1;
     for(int i=3;i*i<M;i+=2)
       if(!b[i])
         for(int j=i*i;j<M;j+=2*i)
           b[j]=1;
     b[1]=1;
     char w[8];
     dp[0]=dp[1]=0;
     dp[2]=1;
     for(int i=3;i<M;i+=2)
     {
          dp[i]=dp[i+1]=dp[i-1];
          if(!b[i])
          {
              int x=0;
              sprintf(w,"%d",i);
              for(int j=0,k=(int)log10(i)+1;j<k;j++)
                 x+=w[j]-'0';
              if(!b[x])dp[i]=dp[i+1]=dp[i-1]+1;
          }
     }     
}

int main()
{
    gen();
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d%d",&a,&b);
         printf("%d\n",dp[b]-dp[a-1]);
    }
    return 0;
}
