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
int g[6][6];
bool vis[6][6];
char ans[11];
int bt(int start, int c)
{
    if(c == 9)
        printf("%s\n",ans);
    else
    {
        for(int i = 1; i < 6; ++i)
        {
            if(g[start][i] && !vis[start][i])
            {
                 ans[c] = i+'0';
                 vis[start][i] = vis[i][start] = 1;          
                 bt(i,c+1);
                 vis[start][i] = vis[i][start] = 0;    
            }
        } 
    }     
}
int main()
{
    memset(g,0,sizeof g);
    memset(vis,0,sizeof vis);
    g[1][2] = g[1][3] = g[1][5] = 1;
    g[2][1] = g[2][3] = g[2][5] = 1;
    g[3][1] = g[3][2] = g[3][4] = g[3][5] = 1;
    g[4][3] = g[4][5] = 1;
    g[5][1] = g[5][2] = g[5][3] = g[5][4] = 1;
    ans[9]='\0';
    ans[0]='1';
    bt(1,1);
    //SP;
    return 0;
}
