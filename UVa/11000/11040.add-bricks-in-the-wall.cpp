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
int m[10][10];
int s[10][10];
int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        for(int i = 0; i < 5; ++i)
           for(int j = 0; j <= i; ++j)
              scanf("%d", &m[i][2 * j]);
        
        for(int i = 0; i < 5; ++i)
        {
           for(int j = 0; j < 2 * i; ++j)
           {
              if(j)printf(" ");
              printf("%d", s[i][j]); 
           }
           if(i)NL;
           for(int j = 0; j < 2 * i + 1; ++j)
           {
               if(j)printf(" ");
               printf("%d", m[i][j]);
           }
           NL;
           for(int j = 0; j <= i; ++j)
              m[i + 1][2 * j + 1] = (m[i][2 * j] - m[i + 1][2 * j] - m[i + 1][2 * j + 2]) / 2;
           /*for(int j = 0; j < 2 * (i + 1) + 1; ++j)
              printf("%d ", m[i + 1][j]);NL;
           SP;*/
           for(int j = 0; j < 2 * (i + 1); ++j)
              s[i + 1][j] = m[i + 1][j] + m[i + 1][j + 1];
           /*for(int j = 0; j < 2 * (i + 1); ++j)
              printf("%d ", s[i + 1][j]);NL;
           SP;*/
        }
    }
    return 0;
}
