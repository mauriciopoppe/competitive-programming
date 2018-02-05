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
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
#define NL printf("\n")
typedef long long LL;

char m[101][101];
int res[101][101],r,c;
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};

bool ok(int x, int y)
{
    if(x>=0 && y>=0 && x<r && y<c)return 1;
    return 0; 
}

void change(int x, int y)
{
    F(k,8)
    {
        int xx=x+dx[k],yy=y+dy[k];
        if(ok(xx,yy) && m[xx][yy]!='*')++res[xx][yy];
    }
    res[x][y]=10;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas=1;
    while(cin>>r>>c && r && c)
    {
        memset(res,0,sizeof(res));
        if(cas!=1)NL;            
        F(i,r)scanf("%s",m[i]);
        F(i,r)
          F(j,c)
              if(m[i][j]=='*')change(i,j);
        
        printf("Field #%d:\n",cas++);
        F(i,r)
        {
          F(j,c)
            if(res[i][j]==10)putchar('*');
            else printf("%d",res[i][j]);
          NL;
        }
    }
    return 0;
}
