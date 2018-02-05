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
    int na, nb, k;
    while(scanf("%d%d", &na, &nb))
    {
        if(na + nb == 0)
           return 0;
        set<int> sa, sb;
        for(int i = 0; i < na; ++i)
           scanf("%d", &k), sa.insert(k);                
        for(int i = 0; i < nb; ++i)
           scanf("%d", &k), sb.insert(k);
           
        TR(sa, it)
           printf("%d ", *it);NL;
        TR(sb, it)
           printf("%d ", *it);NL;
        SP;
        vector<int> v;
        vector<int>::iterator it;
        it = set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), v.begin());
        int size = (int)(it - v.begin());
        printf("%d\n", min(sa.size() - size, sb.size() - size));
    }
    return 0;
}
