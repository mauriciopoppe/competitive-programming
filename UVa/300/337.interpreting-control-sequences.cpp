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
int board[10][11];
int overwrite;
int row, col;
void write_char(char c)
{
    if(overwrite)
    {
       board[row][col++] = c;
       if(col == 10)--col;
    }
    else
    {
       for(int i = 9; i > col; --i)
          board[row][i] = board[row][i - 1];
       board[row][col++] = c;
       if(col == 10)--col;
    }
}

int main()
{
    int cas;
    char w[50000];
    char line[500];
    int n = 1;
    while(scanf("%d", &cas) && cas)
    {
        memset(board, ' ', sizeof board);
        *w = '\0';
        gets(line);
        for(int i = 0; i < cas; ++i)
           gets(line), strcat(w, line);
        //printf("[%s]\n", w);
        row = 0, col = 0;
        overwrite = 1;
        for(int i = 0; w[i]; )
        {
            if(w[i] != '^')
               write_char(w[i++]);
            else
            {
               ++i; 
               if(w[i] == 'b')
                  col = 0;
               else if(w[i] == 'c')
                  memset(board, ' ', sizeof board);
               else if(w[i] == 'd')
               {
                  if(row + 1 < 10) 
                     ++row;
               }
               else if(w[i] == 'e')
                  for(int j = col; j < 10; ++j)
                     board[row][j] = ' ';
               else if(w[i] == 'h')
                  row = col = 0;
               else if(w[i] == 'i')
                  overwrite = 0;
               else if(w[i] == 'l')
               {
                  if(col - 1 >= 0) 
                     --col;
               }
               else if(w[i] == 'o')
                  overwrite = 1;
               else if(w[i] == 'r')
               {
                  if(col + 1 < 10) 
                     ++col;
               }
               else if(w[i] == 'u')
               {
                  if(row - 1 >= 0) 
                     --row;
               }
               else if(w[i] == '^')
                  write_char(w[i]);
               else
               {
                  row = w[i] - '0';
                  col = w[i + 1] - '0';
                  ++i;
               }
               ++i;
            }
            //printf("%c %d %d\n", w[i - 1], row, col);
            //SP;
        }
        printf("Case %d\n", n++);
        puts("+----------+");
        for(int i = 0; i < 10; ++i)
        {
           putchar('|');     
           board[i][10] = '\0';           
           for(int j = 0; j < 10; ++j)        
               putchar(board[i][j]);
           putchar('|');
           putchar(10);
        }
        puts("+----------+");

    }
    return 0;
}
