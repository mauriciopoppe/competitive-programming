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
int a[101][101];
char w[150];
int main()
{
    int cas, row, col;
    while(scanf("%d", &row) && row)
    {
        scanf("%d", &col);
        gets(w);
        for(int i = 0; i < row; ++i)        
        {
             gets(w);
             fill(a[i], a[i] + col, 0);
             for(int j = 0; j < col; ++j)
                if(w[j] == '1')
                   a[i][j] = 1;
        }
        
        int cnt = 0;
        for(int i = 0; i < row; ++i)
           for(int j = 0; j < col; ++j)
              for(int x = i; x < row; ++x)
                 for(int y = j; y < col; ++y)
                 {
                     int p, q;
                     bool f = 1;
                     for(int p = i; p <= x; ++p)
                        for(int q = j; q <= y; ++q)
                           if(!a[p][q])
                              f = 0, p = x + 1, q = y + 1;
                     if(f)
                        //printf("%d,%d  %d,%d\n", i, j, x, y), 
                        cnt++;
                 }
        printf("%d\n", cnt);
    }
    return 0;
}
