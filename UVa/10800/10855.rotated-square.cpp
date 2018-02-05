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
char text[1001][1001];
char pattern[1001][1001];
int total[4], n, m;

void rotate()
{
    char t[1001][1001];
    for(int j = 0, x = 0; j < m; ++j, ++x)
       for(int i = m - 1, y = 0; i >= 0; --i, ++y)
          t[x][y] = pattern[i][j];
    for(int i = 0; i < m; ++i)
       for(int j = 0; j < m; ++j)
          pattern[i][j] = t[i][j];     
}

int check()
{
    int c = 0;
    for(int i = 0; i <= n - m; ++i)
       for(int j = 0; j <= n - m; ++j)
       {
          int f = 1;
          for(int x = 0; x < m && f; ++x)
             for(int y = 0; y < m && f; ++y)
                if(text[i + x][j + y] != pattern[x][y])
                   f = 0;
          if(f) ++c;
       }
    return c;
}

int main()
{   
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        gets(text[0]);
        for(int i = 0; i < n; ++i)
            gets(text[i]);
        for(int i = 0; i < m; ++i)
            gets(pattern[i]);
        memset(total, 0, sizeof total);
        for(int i = 0; i < 4; ++i)
        {            
            total[i] = check();
            rotate();
        }
        for(int i = 0; i < 4; ++i)
        {
           if(i)putchar(' ');
           printf("%d", total[i]);
        }
        NL;
    }
    return 0;
}
