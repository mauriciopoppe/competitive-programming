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
char board[10][10];
int x, y;

int solve()
{
     char c;
     char comm[10000];
     while(gets(comm))
     {
          for(int i = 0; comm[i]; ++i)
          {
              c = comm[i];
              if(c == '0')
                  return 1;  
              if(c == 'A')
              {
                  if(x == 0) return 0;
                  board[x][y] = board[x - 1][y];
                  board[x - 1][y] = ' ';
                  --x;
              }
              else if(c == 'B')
              {
                  if(x == 4) return 0;
                  board[x][y] = board[x + 1][y];
                  board[x + 1][y] = ' ';
                  ++x;
              }
              else if(c == 'L')
              {
                  if(y == 0) return 0;
                  board[x][y] = board[x][y - 1];
                  board[x][y - 1] = ' ';
                  --y;
              }
              else if(c == 'R')
              {
                  if(y == 4) return 0;
                  board[x][y] = board[x][y + 1];
                  board[x][y + 1] = ' ';
                  ++y;
              }
          }
     }
     return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas = 1;
    while(gets(board[0]) && strcmp(board[0], "Z"))
    {
         if(cas != 1)
            NL;
         for(int i = 1; i < 5; ++i)
            gets(board[i]);

         for(int i = 0; i < 5; ++i)                
            for(int j = 0; j < 5; ++j)
               if(board[i][j] == ' ')
                  x = i, y = j, i = j = 5;
         printf("Puzzle #%d:\n", cas++);
         if(solve())
         {
            for(int i = 0; i < 5; ++i)                
            {
              for(int j = 0; j < 5; ++j)
              {
                 if(j)putchar(' ');
                 putchar(board[i][j]);     
              }
              NL;
            }                              
         }
         else
            puts("This puzzle has no final configuration.");
    }    
    return 0;
}
