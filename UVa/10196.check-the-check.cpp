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

int rook_dx[] = {-1, 0, 0, 1}, rook_dy[] = {0, -1, 1, 0};
int bishop_dx[] = {-1, -1, 1, 1}, bishop_dy[] = {-1, 1, -1, 1};
int queen_dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, queen_dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int knight_dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}, knight_dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int x, y;
char board[9][9];

int check(int x1, int y1)
{
    return x1 >= 0 && x1 < 8 && y1 >=0 && y1 < 8;
}

int check_the_check(int type)
{
    int in_check = 0;
    char king = (type == 1 ? 'k' : 'K');
    
    //printf("%c\n", king);
    if(board[x][y] == 'P')
    {
       if(check(x - 1, y - 1))
          in_check |= (board[x - 1][y - 1] == king);
       if(check(x - 1, y + 1))
          in_check |= (board[x - 1][y + 1] == king);       
       return in_check;
    }

    if(board[x][y] == 'p')
    {
       if(check(x + 1, y - 1))
          in_check |= (board[x + 1][y - 1] == king);
       if(check(x + 1, y + 1))
          in_check |= (board[x + 1][y + 1] == king);       
       return in_check;
    }

    if(toupper(board[x][y]) == 'R')
    {
        for(int i = 0; i < 4; ++i)
        {
            int k = 1;
            while(1)
            {
                int nx = x + rook_dx[i] * k, ny = y + rook_dy[i] * k;
                if(!check(nx, ny))
                    break;
                if(isalpha(board[nx][ny]))
                {
                    if(board[nx][ny] == king)
                        return 1;
                    break;                      
                }
                ++k;
            }
        }
        return 0;
    }

    if(toupper(board[x][y]) == 'B')
    {
        for(int i = 0; i < 4; ++i)
        {
            int k = 1;
            while(1)
            {
                int nx = x + bishop_dx[i] * k, ny = y + bishop_dy[i] * k;
                if(!check(nx, ny))
                    break;
                if(isalpha(board[nx][ny]))
                {
                    if(board[nx][ny] == king)
                        return 1;                    
                    break;                      
                }
                ++k;
            }
        }
        return 0;
    }

    if(toupper(board[x][y]) == 'Q')
    {
        for(int i = 0; i < 8; ++i)
        {
            int k = 1;
            while(1)
            {
                int nx = x + queen_dx[i] * k, ny = y + queen_dy[i] * k;
                if(!check(nx, ny))
                    break;
                if(isalpha(board[nx][ny]))
                {
                    if(board[nx][ny] == king)
                        return 1;
                    break;                      
                }
                ++k;
            }
        }
        return 0;
    }

    if(toupper(board[x][y]) == 'N')
    {
        for(int i = 0; i < 8; ++i)
        {
            int nx = x + knight_dx[i], ny = y + knight_dy[i];
            if(check(nx, ny) && board[nx][ny] == king)
                return 1;
        }
        return 0;
    }
    return 0;
}

void solve()
{
    for(x = 0; x < 8; ++x)
       for(y = 0; y < 8; ++y)
       {
           int res;  
           if(isalpha(board[x][y]))
           {
              res = check_the_check(board[x][y] < 95);
              //printf("%c %d\n", board[x][y], res);
              //SP;
           }
           if(res == 1)
           {
              if(board[x][y] >= 95)
              {
                 printf("white king is in check.\n");
                 return;            
              }
              else
              {
                 printf("black king is in check.\n");
                 return;            
              }              
           }
       }
    printf("no king is in check.\n");
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int k = 0;
    while(gets(board[0]))
    {
        if(k)gets(board[0]);
        for(int i = 1; i < 8; ++i)
            gets(board[i]);
        
        int t = 0;
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j)
               if(board[i][j] != '.')
                    t = 1, i = j = 8;
        
        if(!t)break;
        printf("Game #%d: ", ++k);
        solve();
    }
    return 0;
}
