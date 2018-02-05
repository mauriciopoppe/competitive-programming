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
#define M 11
int n,walk;
int g[M][M];
bool d[M][M],f;
bool nodes[M];
int route[M];
void dfs(int x, int length)
{
     if(length==walk)
     {
          f=1;
          printf("(1");
          F(i,walk)
             printf(",%d",route[i]);
          printf(")\n");
     }
     else
     {
         for(int i=0;i<n;i++)
             if(!d[x][i] && g[x][i] && !nodes[i])
             {
                  //printf("%d %d %d\n",length,x,i);
                  d[x][i]=d[i][x]=1;
                  nodes[i]=1;
                  route[length]=i+1;
                  //printf("%d %d\n",route[x],x);
                  //printf("Route: ");
                  //F(j,walk)printf("%d ",route[j]);NL;
                  dfs(i,length+1);
                  d[x][i]=d[i][x]=0;
                  nodes[i]=0;
             }
     }     
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas=0;
    memset(nodes,0,sizeof nodes);
    nodes[0]=1;
    while(scanf("%d%d",&n,&walk)!=EOF)
    {
          if(cas)NL;
          cas=1;
          F(i,n)
            F(j,n)
              scanf("%d",&g[i][j]);
          scanf("%*d");
          f=0;
          memset(route,0,sizeof route);
          dfs(0,0);
          if(!f)printf("no walk of length %d\n",walk);                
    }
    return 0;
}
