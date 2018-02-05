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
#define M 150
int board[M][M];
int discovered[M][M];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int row, col;
int kill, type;
int cnt;

int check(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col;    
}

int dfs(int x, int y)
{
    if(kill)
       board[x][y] = -1;
    discovered[x][y] = 1;
    ++cnt;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(check(nx, ny) && board[nx][ny] == type && !discovered[nx][ny])
           dfs(nx, ny);
    }
}

void print()
{
     for(int i = row - 1; i >= 0; --i)
     {
        printf("    ");     
        for(int j = 0; j < col; ++j)     
        {
           if(j)putchar(' ');
           if(board[i][j] == -1)
              putchar(' ');
           else
              printf("%d", board[i][j]);
        }
        NL;
     }
}

void printR()
{
     for(int i = 0; i < row; ++i)
     {
        for(int j = 0; j < col; ++j)     
           printf("%d ", board[i][j]);NL;}
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas = 1;
    while(scanf("%d%d", &row, &col) && row + col != 0)
    {
         if(cas > 1)NL;
         memset(board, -1, sizeof board);
         for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
               scanf("%d", &board[i][j]);
         int x, y;
         while(scanf("%d%d", &x, &y) && x + y != 0)
         {
              --x, --y;
              if(!check(x, y))
                 continue;
              if(board[x][y] == -1)
                 continue;
              cnt = 0;
              type = board[x][y];
              
              memset(discovered, 0, sizeof discovered);
              kill = 0;
              dfs(x, y);
              if(cnt < 2)
                 continue;
              
              memset(discovered, 0, sizeof discovered);
              kill = 1;
              dfs(x, y);
              
              //fix the board
              int m[M];
              for(int j = 0; j < col; ++j)
              {
                 int k = 0;                 
                 for(int i = 0; i < row; ++i)
                    if(board[i][j] != -1)
                       board[k++][j] = board[i][j];   
                 for(int i = k; i < row; ++i)
                    board[i][j] = -1;
              }
              //printR();NL;
              
              bool f[M];
              memset(m, 0, sizeof m);
              memset(f, 0, sizeof f);
              
              if(board[0][0] == -1) m[0] = 1, f[0] = 1;
              for(int j = 1; j < col; ++j)
                 if(board[0][j] != -1)
                    m[j] = m[j - 1];
                 else
                    m[j] = m[j - 1] + 1, f[j] = 1;

              /*for(int j = 0; j < col; ++j)
                 printf("%d ", m[j]);
              NL;
              printR();NL;*/
                    
              for(int i = 0; i < row; ++i)
              {
                 for(int j = 0; j < col; ++j)  
                    if(!f[j])
                       board[i][j - m[j]] = board[i][j];
                 for(int j = col - 1; j >= col - m[col - 1]; --j)
                    board[i][j] = -1;
              }   
              //printR();NL;
         }
         
         printf("Grid %d.\n", cas++);
         if(board[0][0] == -1)
            printf("    Game Won\n");
         else
            print();
    }
    return 0;
}
