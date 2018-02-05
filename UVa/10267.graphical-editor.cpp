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
int row, col;
char m[260][260];
char w[500];
char com[1000][10];
int dis[260][260];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
char key;
char c[5];

void clear_screen()
{
    for(int i = 0; i < row; ++i)
       for(int j = 0; j < col; ++j)
          m[i][j] = 'O';      
}

void print_board()
{
    for(int i = 0; i < row; ++i)
    {
       for(int j = 0; j < col; ++j)
          putchar(m[i][j]);
       NL;      
    }
}

int check(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col;    
}

void dfs(int x, int y)
{
    dis[x][y] = 1;
    m[x][y] = c[0];
    for(int k = 0; k < 4; ++k)
    {
        int nx = x + dx[k], ny = y + dy[k];
        if(check(nx, ny) && m[nx][ny] == key && !dis[nx][ny])
           dfs(nx, ny);    
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int x1, y1, x2, y2;
    while(scanf("%s", w) && strcmp(w, "X"))
    {
        if(!strcmp(w, "I"))
        {
            scanf("%d%d", &col, &row);
            clear_screen();
        }
        else if(!strcmp(w, "C"))
            clear_screen();
        else if(!strcmp(w, "L"))
        {
            scanf("%d%d%s", &y1, &x1, &c);
            m[x1 - 1][y1 - 1] = c[0]; 
        }
        else if(!strcmp(w, "V"))
        {
            scanf("%d%d%d%s", &y1, &x1, &x2, &c);
            if(x2 < x1) swap(x1, x2);
            for(int i = x1 - 1; i <= x2 - 1; ++i)
               m[i][y1 - 1] = c[0]; 
        }
        else if(!strcmp(w, "H"))
        {
            scanf("%d%d%d%s", &y1, &y2, &x1, &c);
            if(y2 < y1) swap(y1, y2);
            for(int i = y1 - 1; i <= y2 - 1; ++i)
               m[x1 - 1][i] = c[0];              
        }
        else if(!strcmp(w, "K"))
        {
            scanf("%d%d%d%d%s", &y1, &x1, &y2, &x2, &c);
            if(x2 < x1) swap(x1, x2);
            if(y2 < y1) swap(y1, y2);
            for(int i = x1 - 1; i <= x2 - 1; ++i)
               for(int j = y1 - 1; j <= y2 - 1; ++j)
                  m[i][j] = c[0];
        }
        else if(!strcmp(w, "F"))
        {
            scanf("%d%d%s", &y1, &x1, &c);
            key = m[x1 - 1][y1 - 1];
            for(int i = 0; i < row; ++i)
               for(int j = 0; j < col; ++j)
                  dis[i][j] = 0;
            dfs(x1 - 1, y1 - 1);
        }
        else if(!strcmp(w, "S"))
        {
            scanf("%s", w);
            puts(w);
            print_board();
        }
        else gets(w);
    }
    return 0;
}
