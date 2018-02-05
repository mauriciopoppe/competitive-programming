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
typedef pair<int, int> pii;
#define M 51
#define pow2(a) ((a)*(a))
struct point{
       int x, y;
} rect[M][2];

int d2p(point p1, point p2)
{
    return pow2(p1.x - p2.x) + pow2(p1.y - p2.y);
}

bool inside_rectangle(int x, int y, int index)
{
     return x >= rect[index][0].x && x <= rect[index][1].x &&
            y >= rect[index][0].y && y <= rect[index][1].y;
}

int main()
{
    int r_i = 0;
    vector<pii> v;
    vector<bool> kill;
    char w[15];
    int x1, y1, x2, y2;
    while(scanf("%s", w) && w[0] != '#')
    {
         if(w[0] == 'I')
         {
             scanf("%d%d", &x1, &y1);
             v.push_back(pii(x1, y1));
             kill.push_back(0);
         }
         else if(w[0] == 'R')
         {
             scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
             rect[r_i][0].x = x1;
             rect[r_i][0].y = y1;
             rect[r_i][1].x = x2;
             rect[r_i][1].y = y2;
             r_i++;
             int size = v.size();
         }
         else
         {
             scanf("%d%d", &x1, &y1);
             bool f = 0;
             int i;
             int size = v.size();
             
             //kill icons that are inside windows
             for(int j = 0; j < r_i; ++j)             
                 for(int i = 0; i < size; ++i)
                    if(v[i].first <= rect[j][1].x && v[i].first >= rect[j][0].x &&
                       v[i].second <= rect[j][1].y && v[i].second >= rect[j][0].y)
                           kill[i] = 1;
             
             for(i = r_i - 1; i >= 0 && !f; --i)
                 if(inside_rectangle(x1, y1, i))
                     f = 1;
             if(f)
             {
                ++i;  
                printf("%c\n", i + 'A');
                continue;
             }
             
             int mn = 999999999;
             
             point p1, p2;
             p1.x = x1, p1.y = y1;
             for(i = 0; i < size; ++i)
             {
                if(kill[i])
                   continue;   
                p2.x = v[i].first;
                p2.y = v[i].second;                   
                mn = min(mn, d2p(p1, p2));
             }
             
             for(int i = 0; i < size; ++i)
             {
                if(kill[i])
                   continue;
                p2.x = v[i].first;
                p2.y = v[i].second;                   
                if(d2p(p1, p2) == mn)
                   printf("%3d", i + 1);
             }
             NL;
         }
    }
    return 0;
}
