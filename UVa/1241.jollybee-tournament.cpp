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
bool v[15][1500];
int main()
{
    int cas;
    int n, m;
    int k;
    scanf("%d", &cas);
    while(cas--)
    {
         scanf("%d%d", &n, &m);
         for(int i = 1; i <= 1 << n; ++i)
            v[0][i] = 1;
         for(int i = 0; i < m; ++i)
            scanf("%d", &k), v[0][k] = 0;
         
         int s = 0;
         for(int i = n, l = 0; i > 0; --i, ++l)
         {
             /*for(int k = 1; k <= 1 << i; ++k)
                printf("%d ", v[l][k]);NL;*/
             int size = 1 << i;
             for(int j = 1; j <= size; j += 2)
             {
                //printf(">>%d %d\n", v[l][j], v[l][j + 1]);
                if(v[l][j] + v[l][j + 1] == 1)
                   ++s;
                v[l + 1][j / 2 + 1] = v[l][j] || v[l][j + 1];
             }
         }
         printf("%d\n", s);
    }
    return 0;
}
