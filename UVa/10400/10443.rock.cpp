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
int grid[M][M];
int temp[M][M];
int next[] = {1, 2, 0};
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int row, col, play;

int check(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col;    
}

void execute()
{
    F(i, row)
       F(j, col)
          temp[i][j] = -1;
           
    F(i, row)
       F(j, col)
          F(k, 4)
          {
              int nx = i + dx[k], ny = j + dy[k];
              if(check(nx, ny) && grid[nx][ny] == next[grid[i][j]])
                 temp[nx][ny] = grid[i][j];
          }
    
    F(i, row)
       F(j, col)
          if(temp[i][j] != -1)
             grid[i][j] = temp[i][j];
}

int main()
{
    char w[500];
    int cas;
    scanf("%d", &cas);
    F(z, cas)
    {
        if(z)NL;
        scanf("%d%d%d", &row, &col, &play);
        gets(w);
        F(i, row)
        {
           gets(w);
           F(j, col)
              if(w[j] == 'R') grid[i][j] = 0;
              else if(w[j] == 'S') grid[i][j] = 1;
              else grid[i][j] = 2;
        }
        
        F(i, play)
           execute();
        
        F(i, row)
        {
           F(j, col)
              if(grid[i][j] == 0) putchar('R');
              else if(grid[i][j] == 1) putchar('S');
              else putchar('P');
           NL;
        }
    }
    return 0;
}
