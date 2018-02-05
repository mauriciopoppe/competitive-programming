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
#define pow2(a) ((a)*(a))
typedef long long LL;

#define M 20

double d[M][M];
double memo[70000];
int n;
int total;

double dist(pair<double,double> &p1, pair<double,double> &p2)
{
    return sqrt(pow2(p2.first - p1.first) + pow2(p2.second - p1.second));
}

double bt(int bitmask)
{
    if(memo[bitmask] > -0.5) 
       return memo[bitmask];
       
    if(bitmask == total)
       return memo[bitmask] = 0;       
    
    double matching = 32767 * 32767;   
    F(x,n)
    {
        if(!(bitmask & (1 << x)))
        {
            FOR(y,x+1,n)
                if(!(bitmask & (1 << y)))
                  matching = min(matching, d[x][y] + bt(bitmask | (1 << x) | (1 << y)));
            break;
        }
    }
    return memo[bitmask] = matching;
}

int main()
{
    int cas = 0;
    while(scanf("%d",&n) && n)
    {             
        n *= 2;
        total = (1 << n) - 1;             
        vector<pair<double,double> > points(n);
        F(i,n)
        {                       
           scanf("%*s %lf %lf",&points[i].first, &points[i].second);
           F(j,i)
              d[i][j] = d[j][i] = dist(points[i], points[j]);   
        }
        memset(memo, -1, sizeof memo);
        printf("Case %d: %.2lf\n", ++cas, bt(0));
    }
    return 0;
}
