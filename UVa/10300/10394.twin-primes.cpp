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
#define M 20000001
bitset<M+1> b;
int dp[2000000],p[100001];

void gen()
{
     
     for(int i=4;i<M;i+=2)b[i]=1;
     for(int i=3;i*i<M;i+=2)
       if(!b[i])
         for(int j=i*i;j<M;j+=2*i)
           b[j]=1;
     
     int j=0;
     for(int i=3;i<M;i+=2)
        if(!b[i])dp[j++]=i;
     
     int k=0;
     for(int i=1;k<100000;++i)
         if(dp[i]-dp[i-1]==2)p[k++]=dp[i];
     /*
     int j=0;
     for(int i=5;i<M;i+=2)
        if(!b[i] && !b[i-2])p[j++]=i;*/
}
int main()
{
    //long l=clock();
    gen();
    //printf("%ld",clock()-l);
    int t;
    while(scanf("%d",&t)!=EOF)
    {
         printf("(%d, %d)\n",p[t-1]-2,p[t-1]);
    }
    return 0;
}
