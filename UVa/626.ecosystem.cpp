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
int b[101][101];
int main()
{
    /*
    0 1 0
    0 0 1
    1 0 0
    */
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
           for(int j = 0; j < n; ++j)
              scanf("%d", &b[i][j]);
        int total = 0;
        for(int x1 = 0; x1 < n; ++x1)
           for(int y1 = 0; y1 < n; ++y1)
           {              
              if(y1 != x1 && b[x1][y1])
              {
                  //printf("%d %d\n", x1 + 1, y1 + 1);SP;
                  int mx = 0, mn = 0;         
                  if(x1 > y1) ++mx;
                  else ++mn;
                  
                  for(int y2 = 0; y2 < n; ++y2)
                     if(y2 != x1 && y2 != y1 && b[y1][y2] && b[y2][x1])
                     {
                         //printf(">%d %d %d\n", y1 + 1, y2 + 1, x1 + 1);SP;
                         int mx1 = 0, mn1 = 0  ;
                         if(y1 > y2) ++mx1;
                         else ++mn1;
                         
                         if(mx + mx1 && mn + mn1)
                            continue;
                         else
                            printf("%d %d %d\n", x1 + 1, y1 + 1, y2 + 1), ++total;
                     }
              }
           }
        printf("total:%d\n\n", total);        
    }
    return 0;
}
