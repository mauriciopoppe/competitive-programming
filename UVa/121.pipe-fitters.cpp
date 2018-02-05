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

int solve_grid(double x, double y)
{
    return (int) x * (int) y; 
}

int solve_skew(double x, double y)
{
    if(x < 1 || y < 1)
       return 0;
    int row[2] = {(int) x, (int) (x - 0.5)};
    int f = 1;
    double H = 1;
    double h = 0.5 * sqrt(3);
    int total = row[0];
    while(H + h <= y)
    {
        H += h;
        total += row[f];
        f = !f;
    }
    return total;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    double x, y;    
    while(scanf("%lf%lf", &x, &y) != EOF)
    {
        int grid = solve_grid(x, y), skew = max(solve_skew(x, y), solve_skew(y, x));
        if(grid >= skew) printf("%d grid\n", grid);
        else printf("%d skew\n", skew);                  
    }
    return 0;
}
