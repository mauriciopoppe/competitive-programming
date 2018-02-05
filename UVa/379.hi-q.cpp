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

int score[][7] = {{  0,  0,  1,  2,  3,  0,  0},
                  {  0,  0,  4,  5,  6,  0,  0},
                  {  7,  8,  9, 10, 11, 12, 13},
                  { 14, 15, 16, 17, 18, 19, 20},
                  { 21, 22, 23, 24, 25, 26, 27},
                  {  0,  0, 28, 29, 30,  0,  0},
                  {  0,  0, 31, 32, 33,  0,  0}};
                  
int board[7][7];
int dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};
int row, col;

void put_peg(int k)
{
    for(; row < 7; ++row)
       for(col = 0; col < 7; ++col)
       {
          //printf("%d %d %d\n", score[row][col], row, col);
          //SP;
          if(score[row][col] == k)
          {
             board[row][col] = 1;      
             return;
          }
       }
}

int check(int x, int y)
{
    return x >= 0 && x < 7 && y >= 0 && y < 7 && score[x][y] && board[x][y];   
}

void print_board()
{
    for(int i = 0; i < 7; ++i)
    {
       for(int j = 0; j < 7; ++j)
          if(score[i][j])
          {
              if(board[i][j]) printf("%2d ", score[i][j]);
              else printf(" O ");
          }
          else
             printf("   ");
       NL;
    }
}

void solve()
{
    int to_move; 
    int nx, ny;
    int dir;
    while(1)
    {
        //print_board();
        //SP;
        to_move = 0;
        for(int i = 6; i >= 0; --i)      
           for(int j = 6; j >= 0; --j)
              if(score[i][j] && !board[i][j])
                 for(int k = 0; k < 4; ++k)
                 {
                     if(check(i + dx[k], j + dy[k]) && check(i + 2 * dx[k], j + 2 * dy[k]))
                     {
                         board[i][j] = 1;
                         board[i + dx[k]][j + dy[k]] = 0;
                         board[i + 2 * dx[k]][j + 2 * dy[k]] = 0;
                         to_move = 1;
                         goto end;       
                     }   
                 }
        end:
            if(!to_move)
               break;                
    }
    int sum = 0;
    for(int i = 0; i < 7; ++i)
       for(int j = 0; j < 7; ++j)
          if(score[i][j] && board[i][j])
             sum += score[i][j];
    printf("%d\n", sum);    
}


int main()
{
    int n, k;
    scanf("%d", &n);
    puts("HI Q OUTPUT");
    while(n--)
    {
         row = 0, col = 0;
         memset(board, 0, sizeof board);
         while(scanf("%d", &k) && k)
            put_peg(k);
         solve();
    }
    puts("END OF OUTPUT");
    return 0;
}
