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
#define pii pair<int,int>
#define NL printf("\n")
#define SP system("pause")
#define INF 2000000000
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 15
int row,col;
char w[M][M];
int d[M][M];
bool check(int &x, int &y)
{
     if(x>=0 && y>=0 && x<row && y<col)return true;
     return false;
}
int main()
{
    map<char,pair<int,int> > m;
    m['E']=pii(0,1);
    m['W']=pii(0,-1);
    m['N']=pii(-1,0);
    m['S']=pii(1,0);
    int start;
    while(scanf("%d%d%d",&row,&col,&start))
    {
         if(row+col+start==0)break;
         F(i,row)scanf("%s",w[i]);                                  
         int sx=0,sy=start-1,f=1,dx,dy;
         memset(d,0,sizeof d);
         d[sx][sy]=1;
         while(1)
         {
              char c=w[sx][sy];
              dx=sx+m[c].first, dy=sy+m[c].second;
              if(check(dx,dy))
              {
                   if(!d[dx][dy])
                   {
                        d[dx][dy]=d[sx][sy]+1;
                        sx=dx,sy=dy;         
                   }
                   else {f=0;break;}
              }
              else break;
         }
         if(f)printf("%d step(s) to exit\n",d[sx][sy]);
         else printf("%d step(s) before a loop of %d step(s)\n",d[dx][dy]-1,d[sx][sy]-d[dx][dy]+1);
    }        
    return 0;
}
