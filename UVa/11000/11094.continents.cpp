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
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int row, col, c;
char grid[21][21];
char key;
bool dis[21][21];

int check(int &x, int &y)
{
    if(y == -1)
       y = col - 1;
    if(y == col)
       y = 0;
    return x >= 0 && x < row && y >= 0 && y < col;
}

void dfs(int x, int y)
{
    ++c;
    dis[x][y] = 1;
    F(i,4)
    {
        int sx = x + dx[i], sy = y + dy[i];
        if(check(sx, sy) && grid[sx][sy] == key && !dis[sx][sy])
           dfs(sx, sy);  
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int x, y;
    while(scanf("%d%d", &row, &col) != EOF)
    {
        getchar();                
        F(i, row)
           gets(grid[i]);
        scanf("%d%d", &x, &y);
        key = grid[x][y];
        c = 0;
        int mx = 0;
        memset(dis, 0, sizeof dis);
        dfs(x, y);
        F(i,row)
          F(j, col)
            if(grid[i][j] == key && !dis[i][j])
            {
                c = 0;
                dfs(i, j);
                mx = max(mx, c);
            }
        printf("%d\n",mx);
               
    }        
    return 0;
}
