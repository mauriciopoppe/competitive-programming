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
#define M 1000
char maze[M][M];
int vis[M][M];
int row, col;
int dir;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

int check(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col;    
}

int can_advance(int x, int y)
{
    //printf("%d %d %d\n", x, y, dir);
    int nx = x + dx[dir], ny = y + dy[dir];
    if(!check(nx, ny) || (check(nx, ny) && maze[nx][ny] == '1'))
       return 0;
    int right = dir - 1;
    if(right < 0) right += 4;
    nx = x + dx[right], ny = y + dy[right];
    return (check(nx, ny) && maze[nx][ny] == '1') || !check(nx, ny);
}

int can_turn_right(int x, int y)
{
    int right = dir - 1;
    if(right < 0) right += 4;
    int right_2 = dir - 2;
    if(right_2 < 0) right_2 += 4;
    
    return check(x + dx[right], y + dy[right]) &&
           maze[x + dx[right]][y + dy[right]] == '0' &&
           check(x + dx[right] + dx[right_2], y + dy[right] + dy[right_2]) &&
           maze[x + dx[right] + dx[right_2]] [y + dy[right] + dy[right_2]] == '1';
}

void print_board()
{
    for(int i = 0; i < row; ++i)
    {
       for(int j = 0; j < col; ++j)
          printf("%2d ",vis[i][j]) ;NL;}      
}

int main()
{
    while(scanf("%d%d", &row, &col) && row && col)
    {
         gets(maze[0]);
         for(int i = 0; i < row; ++i)
            gets(maze[i]);
         
         for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
               vis[i][j] = 0;
         
         int sx = row - 1, sy = 0;
         dir = 0;
         while(1)
         {
             if(can_turn_right(sx, sy))
             {
                 dir = dir - 1;
                 if(dir < 0) dir += 4;
             }
             else
             {
                 while(!can_advance(sx, sy))
                 {
                     dir++;
                     if(dir == 4) dir = 0;
                     //printf("%d\n", dir);               
                 }
             }
             sx += dx[dir], sy += dy[dir];
             ++vis[sx][sy];
             if(sx == row - 1 && sy == 0)
                break;

             //print_board();
             //SP;
         }
         vector<int> v(5, 0);
         for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                if(maze[i][j] == '0')
                   v[vis[i][j]]++;
         printf("%3d%3d%3d%3d%3d\n", v[0], v[1], v[2], v[3], v[4]);
    }
    return 0;  
}
