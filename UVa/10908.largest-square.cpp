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
#define M 110
char w[M][M];
int row, col, q;

int main()
{
    int cas;
    int x, y;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d%d", &row, &col, &q);
        gets(w[0]);
        for(int i = 0; i < row; ++i)
           gets(w[i]);
        printf("%d %d %d\n", row, col, q);
        for(int z = 0; z < q; ++z)
        {
            scanf("%d%d", &x, &y);
            char c = w[x][y];
            int total = 1;
            bool f = 1;
            for(int i = 1; f && x - i >= 0 && x + i < row && y - i >= 0 && y + i < col; ++i)
            {
                for(int j = x - i; j <= x + i; ++j)
                   for(int k = y - i; k <= y + i; ++k)
                      if(w[j][k] != c)
                           f = 0, j = x + i + 1, k = y + i + 1;
                if(f)
                   total += 2;                   
            }
            printf("%d\n", total);
        }        
    }
    return 0;
}
