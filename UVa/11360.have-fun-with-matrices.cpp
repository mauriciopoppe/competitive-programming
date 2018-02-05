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
char m[1000][1000];
int n;
void swap_row(int x, int y)
{
    for(int j = 0; j < n; ++j)
       swap(m[x][j], m[y][j]);      
}

void swap_column(int x, int y)
{
    for(int i = 0; i < n; ++i)
       swap(m[i][x], m[i][y]);      
}

void transpose()
{
    char t[1000][1000];
    for(int i = 0, y = 0; i < n; ++i, ++y)
       for(int j = 0, x = 0; j < n; ++j, ++x)
          t[x][y] = m[i][j];
    for(int i = 0; i < n; ++i)
       for(int j = 0; j < n; ++j)
          m[i][j] = t[i][j];           
}

void print_board()
{
    for(int i = 0; i < n; ++i)
       puts(m[i]);
}

int main()
{
    int cas, x, y, operations;
    char option[50];
    scanf("%d", &cas);
    F(z, cas)
    {
        scanf("%d", &n);
        gets(m[0]);
        for(int i = 0; i < n; ++i)
           gets(m[i]);
        scanf("%d", &operations);
        for(int q = 0; q < operations; ++q)
        {
           scanf("%s", &option);
           if(option[0] == 'r')
              scanf("%d%d", &x, &y),
              swap_row(x - 1, y - 1);
           else if(option[0] == 'c')
              scanf("%d%d", &x, &y),
              swap_column(x - 1, y - 1);
           else if(option[0] == 'i')
           {
              for(int i = 0; i < n; ++i)
                 for(int j = 0; j < n; ++j)  
                 {
                    ++m[i][j];
                    if(m[i][j] == '9' + 1)
                       m[i][j] = '0';
                 }
           }
           else if(option[0] == 'd')
           {
              for(int i = 0; i < n; ++i)
                 for(int j = 0; j < n; ++j)  
                 {
                    --m[i][j];
                    if(m[i][j] == '0' - 1)
                       m[i][j] = '9';
                 }
           }
           else
              transpose();
        }
        printf("Case #%d\n", z + 1);
        print_board(); 
        NL;
    }
    return 0;
}
