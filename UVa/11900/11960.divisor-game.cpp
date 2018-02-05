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
#define M 1000000
int v[M+1],dp[M+1];
int main()
{
    for(int i=2;i*2<=M;i++)
        for(int j=i;j<=M;j+=i)
           v[j]++;
    
    dp[1]=1;
    int best=1,ind=1;
    
    for(int i=2;i<=M;i++)
    {
        if(v[i]>=best)
           dp[i]=ind=i,best=v[i];
        else dp[i]=ind;  
    }       
    
    int n,k;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);      
        printf("%d\n",dp[k]);
    }
    return 0;
}
