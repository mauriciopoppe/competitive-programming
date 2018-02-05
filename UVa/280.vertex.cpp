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
#define M 101
bool g[M][M];
bool d[M];

void dfs(int n)
{
     //printf("\nOUT %d - ",n);
     //if()
     F(i,M)
        if(g[n][i] && !d[i])
          d[i]=1,dfs(i);
}

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
          int st,to;
          memset(g,0,sizeof g);
          while(scanf("%d",&st)&&st)
               while(scanf("%d",&to)&&to)
                 g[st][to]=1;
          scanf("%d",&st);
          F(i,st)
          {
               scanf("%d",&to);
               memset(d,0,sizeof d);
               dfs(to);
               int c=0;
               for(int i=1;i<=n;i++)
                  if(!d[i])c++;
               printf("%d",c);
               for(int i=1;i<=n;i++)
                  if(!d[i])printf(" %d",i);
               NL;
          }
    }
    return 0;
}
