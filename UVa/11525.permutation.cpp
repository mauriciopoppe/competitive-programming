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
    int cas;
    int n, k;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        list<int> v;
        list<int>::iterator it;
        for(int i = 0; i < n; ++i)
            v.push_back(i + 1);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &k);
            it = v.begin();
            advance(it, k);
            if(i)putchar(' ');
            printf("%d", *it);
            v.erase(it);
        }
        NL;
    }
    return 0;
}
