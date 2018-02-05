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

#define pow2(x)  ((x) * (x))  
 
struct point {
    LL x, y;
};
 
point P[100010], Q[100010];                   //points
int N;                                               //number of points
int K;                                               //number of points in the box (y-sorted) 
LL best;                                      //best distance found
 
LL dist(const point &p1, const point &p2) 
{
    return max(abs(p1.x - p2.x), abs(p1.y - p2.y));
}
 
bool byXY(const point &p1, const point &p2)
{
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
 
bool byYX(const point &p1, const point &p2) {
    return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}
 
void rec(int low, int up) {
    if (up - low < 64) 
    {
        //if the points are less than 64 it's better to compute the distance
        //than to keep doing more recursive calls   
        for (int i = low; i <= up; i++)
            for (int j = i + 1; j <= up; j++)
                best = min(best, dist(P[i], P[j]));
        return;
    }
 
    int mid = (low + up) / 2;
    LL midX = P[mid].x;
 
    rec(low, mid);
    rec(mid + 1, up);
 
    //find the points inside the box which have 
    //a x-coordinate distance less than the best
    K = 0;
    for (int i = low; i <= up; i++)
        if (abs(P[i].x - midX) < best) 
           Q[K++] = P[i];
 
    //sort points by their y coordinate
    sort(Q, Q+K, byYX);
 
    //find the best distance
    for (int i = 0; i < K; i++)
        for (int j = i + 1; j < K && abs(Q[j].y - Q[i].y) < best; j++)
            best = min(best, dist(P[i], P[j]));
}


int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
           scanf("%lld%lld", &P[i].x, &P[i].y);
        if(n <= 1)
        {
           printf("0\n");
           continue;
        }
        best = 999999999LL;
        rec(0, n - 1);
        printf("%lld\n", best);
    }
    return 0;
}
