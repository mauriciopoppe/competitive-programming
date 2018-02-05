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
int board[9][9];
int current, other;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0 ,1};

void print_board()
{
    for(int i = 0; i < 8; ++i)
    {
       for(int j = 0; j < 8; ++j)
          if(board[i][j] == 1)putchar('B');
          else if(board[i][j] == 0)putchar('W');
          else putchar('-');
       NL;
    }           
}

int check(int x, int y)
{
    return x >=0 && x < 8 && y >=0 && y < 8;    
}

int is_a_possible_move(int i, int j)
{
   for(int k = 0; k < 8; ++k)
   {
      int c = 1;
      int nx, ny;
      while(1)
      {
          nx = i + dx[k] * c, ny = j + dy[k] * c;
          if(check(nx, ny) && board[nx][ny] == other)
             ++c;
          else break;
      }
      if(c > 1 && check(nx, ny) && board[nx][ny] == current)
         return 1;
   }
   return 0;
}

void check_all_possible()
{
    int f = 0;
    for(int i = 0; i < 8; ++i)
       for(int j = 0; j < 8; ++j)
       {                          
          if(board[i][j] == -1 && is_a_possible_move(i, j))
          {                   
              if(f)printf(" ");
              printf("(%d,%d)", i + 1, j + 1);
              ++f;
          }              
       }
    if(!f)printf("No legal move.");
    NL;
}

void execute_move(int x, int y)
{
   for(int k = 0; k < 8; ++k)
   {
      int c = 1;
      int nx, ny;
      while(1)
      {
          nx = x + dx[k] * c, ny = y + dy[k] * c;
          if(check(nx, ny) && board[nx][ny] == other)
             ++c;
          else break;
      }
      if(c > 1 && check(nx, ny) && board[nx][ny] == current)
      {
          board[x][y] = current;
          for(int i = 1; i < c; ++i)
          {
             nx = x + dx[k] * i, ny = y + dy[k] * i;
             board[nx][ny] = current;
          } 
      }
   }
}

void try_to_move(int x, int y)
{
    if(!is_a_possible_move(x, y))
    {
       current = 1 - current;
       other = 1 - other;
    }
    execute_move(x, y);
    current = 1 - current;
    other = 1 - other;
    //print_board();
    int white = 0, black = 0;
    for(int i = 0; i < 8; ++i)
       for(int j = 0; j < 8; ++j)
          if(board[i][j] == 1) 
             black++;
          else if(board[i][j] == 0)
             white++;
    printf("Black - %2d White - %2d\n", black, white);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    char w[15];
    scanf("%d", &cas);
    while(cas--)
    {
        for(int i = 0; i < 8; ++i)
        {
            scanf("%s", w);
            for(int j = 0; j < 8; ++j)
               if(w[j] == 'W')
                  board[i][j] = 0;
               else if(w[j] == 'B')
                  board[i][j] = 1;
               else
                  board[i][j] = -1;     
        }
        scanf("%s", w);
        current = w[0] == 'W' ? 0 : 1;
        other = 1 - current;
        while(scanf("%s", w) && w[0] != 'Q')
        {
            if(w[0] == 'L')
               check_all_possible();
            else if(w[0] == 'M')
            {
               int nx = w[1] - '0' - 1;
               int ny = w[2] - '0' - 1;
               try_to_move(nx, ny);
            }
        }
        print_board();
        if(cas)NL;
    }
    return 0;
}
