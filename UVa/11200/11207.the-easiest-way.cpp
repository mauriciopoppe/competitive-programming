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

int main()
{   
    int n, w, h;
    while(scanf("%d", &n) && n)
    {                   
        double mx = -1;
        int ind = -1;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &w, &h);
            if(w > h)
               swap(w, h);
            double k;
            if(h >= 4 * w)
                k = (double)w;
            else
                k = (double)h / 4.0;
            double t = max(w * 0.5, k);
            if(t > mx)
                mx = t, ind = i + 1; 
        }
        printf("%d\n", ind);
    }
    return 0;
}
