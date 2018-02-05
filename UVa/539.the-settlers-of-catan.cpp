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
#define M 30
bool g[M][M];
int d[M][M];

int dfs(int x)
{
    //d[x]=1;
    int s=0;
    F(i,M)
      if(g[x][i] && !d[x][i])
      {
         d[i][x]=d[x][i]=1;
         s=max(s,dfs(i)+1);
         d[i][x]=d[x][i]=0;
      }
    return s;
}

int main()
{
    int n,c,x,y;
    while(scanf("%d%d",&n,&c))
    {
         if(n+c==0)break;         
         memset(g,0,sizeof g);
         F(i,c)
           scanf("%d%d",&x,&y),
           g[x][y]=g[y][x]=1;
         int mx=0;
         F(i,n)
         {
            //memcpy(d,g,sizeof g); 
            memset(d,0,sizeof d);  
            //d[i]=1;
            mx=max(mx,dfs(i));
         }
         printf("%d\n",mx);
    }
    return 0;
}
