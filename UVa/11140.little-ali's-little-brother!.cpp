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
char m[55][55], to_check[55][55];
int row, col;

int check(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col;    
}

int solve(int &other_row, int &other_col)
{
     int needed = 0;
     for(int i = 0; i < other_row; ++i)
        for(int j = 0; j < other_col; ++j)
           if(to_check[i][j] == '*')
              ++needed; 
    
     for(int i = 1 - other_row; i < row; ++i)
        for(int j = 1 - other_col; j < col; ++j)
        {
            int total = 0;
            for(int x = i; x < i + other_row; ++x)
               for(int y = j; y < j + other_col; ++y)
                  if(check(x, y) && to_check[x - i][y - j] == '*')
                     total += m[x][y] == to_check[x - i][y - j];
            if(total == needed) return true;
        }
     return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    int test_cases;
    int x, y;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d%d", &row, &col, &test_cases);
        gets(m[0]);
        for(int i = 0; i < row; ++i)
            gets(m[i]);
        for(int k = 0; k < test_cases; ++k)
        {
            scanf("%d%d", &x, &y);
            gets(to_check[0]);
            for(int z = 0; z < x; ++z)
               gets(to_check[z]);
            if(solve(x, y))
               puts("Yes");
            else
               puts("No");
        }
        NL;
    }
    return 0;
}
