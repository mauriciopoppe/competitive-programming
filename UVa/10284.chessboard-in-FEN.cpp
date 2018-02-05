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
int king_dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, king_dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int x, y;
char board[9][9];
int n[9][9];

int check(int x1, int y1)
{
    return x1 >= 0 && x1 < 8 && y1 >=0 && y1 < 8;
}

void attack()
{
    if(board[x][y] == 'P')
    {
       if(check(x - 1, y - 1))
          n[x - 1][y - 1]++;
       if(check(x - 1, y + 1))
          n[x - 1][y + 1]++;
       return;
    }

    if(board[x][y] == 'p')
    {
       if(check(x + 1, y - 1))
          n[x + 1][y - 1]++;
       if(check(x + 1, y + 1))
          n[x + 1][y + 1]++;
       return;
    }

    if(toupper(board[x][y]) == 'R')
    {
        for(int i = 0; i < 4; ++i)
        {
            int k = 1;
            while(1)
            {
                int nx = x + rook_dx[i] * k, ny = y + rook_dy[i] * k;
                if(check(nx, ny) && !isalpha(board[nx][ny]))
                    n[nx][ny]++;
                else
                    break;
                ++k;
            }
        }
        return;
    }

    if(toupper(board[x][y]) == 'B')
    {
        for(int i = 0; i < 4; ++i)
        {
            int k = 1;
            while(1)
            {
                int nx = x + bishop_dx[i] * k, ny = y + bishop_dy[i] * k;
                if(check(nx, ny) && !isalpha(board[nx][ny]))
                    n[nx][ny]++;
                else
                    break;
                ++k;
            }
        }
        return;
    }

    if(toupper(board[x][y]) == 'Q')
    {
        for(int i = 0; i < 8; ++i)
        {
            int k = 1;
            while(1)
            {
                int nx = x + queen_dx[i] * k, ny = y + queen_dy[i] * k;
                if(check(nx, ny) && !isalpha(board[nx][ny]))
                    n[nx][ny]++;
                else
                    break;
                ++k;
            }
        }
        return;
    }

    if(toupper(board[x][y]) == 'N')
    {
        for(int i = 0; i < 8; ++i)
        {
            int nx = x + knight_dx[i], ny = y + knight_dy[i];
            if(check(nx, ny) && !isalpha(board[nx][ny]))
                n[nx][ny]++; 
        }
        return;
    }

    if(toupper(board[x][y]) == 'K')
    {
        for(int i = 0; i < 8; ++i)
        {
            int nx = x + king_dx[i], ny = y + king_dy[i];
            if(check(nx, ny) && !isalpha(board[nx][ny]))
                n[nx][ny]++; 
        }
        return;
    }
}

void solve()
{
    memset(n, 0, sizeof n); 
    for(x = 0; x < 8; ++x)
       for(y = 0; y < 8; ++y)
       {
           int res;  
           if(isalpha(board[x][y]))
           {
               n[x][y] = 1;
               attack();
               /*printf("%d %d %c\n", x, y, board[x][y]);
               F(i, 8){F(j, 8)printf("%d ", n[i][j]);NL;}
               SP;*/
           }
       }
    int k = 0;
    for(x = 0; x < 8; ++x)
       for(y = 0; y < 8; ++y)
          if(n[x][y] == 0)
             ++k;
    printf("%d\n", k);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int k = 0;
    char w[100];    
    while(gets(w))
    {
        memset(board, '.', sizeof board);
        int k = 0;
        for(int i = 0; w[i]; ++i)
        {
            if(isalpha(w[i]))
               board[k / 8][k % 8] = w[i], ++k;
            else if(isdigit(w[i]))
               k += w[i] - '0';
            //printf("%d\n", k);
        }
        /*for(int i = 0; i < 8; ++i)
            board[i][8] = '\0', printf("%s\n", board[i]);
        SP;*/
        solve();
    }
    return 0;
}
