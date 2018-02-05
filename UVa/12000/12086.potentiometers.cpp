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

int st[200000 * 5];
int v[200005];
int LEFT, RIGHT;

void build(int n, int start, int end)
{
     if(start == end)
        st[n] = v[start];
     else
     {
         int mid = (start + end) >> 1;
         build(2 * n, start, mid);
         build(2 * n + 1, mid + 1, end);
         st[n] = st[2 * n] + st[2 * n + 1];
     }
}

int query(int n, int start, int end)
{
     if(LEFT <= start && end <= RIGHT)
         return st[n];
     
     int mid = (start + end) >> 1;
     if(RIGHT <= mid)
         return query(2 * n, start, mid);
     if(LEFT > mid)
         return query(2 * n + 1, mid + 1, end);
     return query(2 * n, start, mid) + query(2 * n + 1, mid + 1, end);
}

void update(int n, int start, int end)
{
     if(LEFT <= start && end <= RIGHT)
     {
        st[n] = v[LEFT];
        return;
     }
     int mid = (start + end) >> 1;
     if(RIGHT <= mid)
         update(2 * n, start, mid);
     else
         update(2 * n + 1, mid + 1, end);
     st[n] = st[2 * n] + st[2 * n + 1];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    char w[500], type[500];
    int cas = 0;
    while(scanf("%d", &n) && n)
    {        
        for(int i = 0; i < n; ++i)
           scanf("%d", &v[i]);
        build(1, 0, n - 1);
        if(cas) NL;
        printf("Case %d:\n", ++cas);
        gets(w);
        while(gets(w) && w[0] != 'E')
        {
            sscanf(w, "%s%d%d", type, &LEFT, &RIGHT);
            if(type[0] == 'M')
            {
               --LEFT;
               --RIGHT;
               printf("%d\n", query(1, 0, n - 1));
            }
            else
            {
               v[--LEFT] = RIGHT;
               RIGHT = LEFT;
               update(1, 0, n - 1);
            }
        }
    }
    return 0;
}
