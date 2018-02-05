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
 
struct point{
       int x, y;
} p0;
 
int cross_product(const point &p1, const point &p2, const point &p3)
{
     return (p2.x - p1.x) * (p3.y - p1.y)
            - (p3.x - p1.x) * (p2.y - p1.y);
}

int check(vector<point> &P, int &n)
{
    //initial check with the first three points
    int value = 0;
    for(int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n, k = (i + 2) % n;
        int cross = cross_product(P[i], P[j], P[k]);
        if(cross != 0)
        {
            value = cross;
            break;
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n, k = (i + 2) % n;
        int cross = cross_product(P[i], P[j], P[k]);
        if(cross * value < 0)
           return false;
    }
    return true;
}

int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
         vector<point> P(n);
         for(int i = 0; i < n; ++i)
            scanf("%d%d", &P[i].x, &P[i].y);
         
         if(check(P, n))
            puts("NO");
         else
            puts("YES");
    }
    return 0;
}
