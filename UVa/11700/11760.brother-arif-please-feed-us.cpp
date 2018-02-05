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
int person[3000][2];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int row, col, n;

int check(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col;    
}

int check_move(int x, int y)
{
    for(int i = 0; i < n; ++i)
       if(person[i][0] == x || person[i][1] == y)
          return 0;
    return 1;
}

int solve(int x, int y)
{
    if(check_move(x, y))
        return 1;
    for(int i = 0; i < 4; ++i)
    {
       int nx = x + dx[i], ny = y + dy[i];
       if(check(nx, ny) && check_move(nx, ny))
          return 1;
    }
    return 0;
}

int main()
{
    int x, y;
    int cas = 1;
    while(scanf("%d%d%d", &row, &col, &n) && n)
    {
         for(int i = 0; i < n; ++i)
            scanf("%d%d", &person[i][0], &person[i][1]);
         scanf("%d%d", &x, &y);
         printf("Case %d: ", cas++);
         if(solve(x, y))
             puts("Escaped again! More 2D grid problems!");
         else
             puts("Party time! Let's find a restaurant!");   
    }
    return 0;
}
