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
#define M 15
char board[M][M];
bool f[M][M];
int n[M][M];
int row, col;

int check(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char w[50];
    int cas = 1;
    while(gets(w) && strcmp(w, "0"))
    {
         if(cas > 1)NL;         
         sscanf(w,"%d%d", &row, &col);
         F(i, row)
            gets(board[i]);
         memset(n, -1, sizeof n);
         
         int k = 1;
         F(i, row)
            F(j, col)
            {
                if(board[i][j] == '*')
                   n[i][j] = 0;
                else if(check(i - 1, j) && board[i - 1][j] == '*')
                   n[i][j] = k++;
                else if(check(i, j - 1) && board[i][j - 1] == '*')
                   n[i][j] = k++;
                else if(!check(i - 1, j) || !check(i, j - 1))
                   n[i][j] = k++;
            }
                   
         //F(i, row){F(j, col) printf("%2d ", n[i][j]);NL;}
         printf("puzzle #%d:\n", cas++);
         printf("Across\n");                    
         memset(f, 0, sizeof f);
         F(i, row)
           F(j, col)
           {
               if(!f[i][j] && n[i][j] > 0) 
               {
                  printf("%3d.%c", n[i][j], board[i][j]);
                  while(1)
                  {
                      if(!check(i, j + 1))
                         break;
                      if(check(i, j + 1) && n[i][j + 1] == 0)
                         break;
                      f[i][j + 1] = 1;
                      putchar(board[i][j + 1]);
                      ++j;
                  }
                  NL;
               }
           }
         printf("Down\n");
         memset(f, 0, sizeof f);
         F(i, row)
           F(j, col)
           {
               if(!f[i][j] && n[i][j] > 0) 
               {
                  int k = i;
                  printf("%3d.%c", n[i][j], board[i][j]);
                  while(1)
                  {
                      if(!check(k + 1,j))
                         break;
                      if(check(k + 1, j) && n[k + 1][j] == 0)
                         break;
                      f[k + 1][j] = 1;
                      putchar(board[k + 1][j]);
                      ++k;
                  }
                  NL;
               }
           }
    }
    return 0;
}
