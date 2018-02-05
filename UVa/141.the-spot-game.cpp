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
int play[100][51][51];
int board[51][51];
int n;
int check(int k)
{
    int f = 1;
    //check normal
    for(int i = 0; i < n && f; ++i)
       for(int j = 0; j < n && f; ++j)
          if(board[i][j] != play[k][i][j])
             f = 0;
    
    if(f) return 1;
    f = 1;
    
    //check 90deg
    for(int i = 0, y = n - 1; i < n && f; ++i, --y)
       for(int j = 0, x = 0; j < n && f; ++j, ++x)
          if(play[k][i][j] != board[x][y])
             f = 0;
             
    if(f) return 1;
    f = 1;

    //check -90deg
    for(int i = 0, y = 0; i < n && f; ++i, ++y)
       for(int j = 0, x = n - 1; j < n && f; ++j, --x)
          if(play[k][i][j] != board[x][y])
             f = 0;
             
    if(f) return 1;
    f = 1;
    
    //check 180deg
    for(int i = 0, x = n - 1; i < n && f; ++i, --x)
       for(int j = 0, y = n - 1; j < n && f; ++j, --y)
          if(play[k][i][j] != board[x][y])
             f = 0;
             
    if(f) return 1;
    return 0;
}

void copy(int k)
{
     for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
           play[k][i][j] = board[i][j];
}

int main()
{
    int x, y;
    int on_move, win;
    char move[2];
    while(scanf("%d", &n) && n)
    {
        win = 0;
        on_move = -1;
        memset(board, 0, sizeof board);
        for(int i = 0; i < 2 * n; ++i)
        {
            scanf("%d%d%s", &x, &y, move);
            if(win) continue;

            --x, --y;
            if(move[0] == '+') board[x][y] = 1;
            else board[x][y] = 0;            
            
            /*F(x, n)
               {F(y, n)
                  printf("%d ", board[x][y]);NL;}
            NL;puts(" - - - - -");*/
            
            for(int j = 0; j < i; ++j)
            {
                /*F(x, n)
                   {F(y, n)
                      printf("%d ", play[j][x][y]);NL;}
                NL;puts(" - - - - -");   
                SP; */
                if(check(j))
                {
                   win = 2 - (i & 1), on_move = i + 1;                   
                   break;
                }
            }
            copy(i);
        }
        if(win) printf("Player %d wins on move %d\n", win, on_move);
        else puts("Draw");
    }
    return 0;
}
