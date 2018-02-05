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
    int t1, t2, final, att, v[3];
    scanf("%d", &cas);
    F(z, cas)
    {
       scanf("%d%d%d%d%d%d%d", &t1, &t2, &final, &att, &v[0], &v[1], &v[2]);
       if(v[0] < v[1]) swap(v[0], v[1]);
       if(v[0] < v[2]) swap(v[0], v[2]);
       if(v[1] < v[2]) swap(v[1], v[2]);
       int total = t1 + t2 + final + att + (v[0] + v[1]) / 2;
       printf("Case %d: ", z + 1);
       if(total >= 90)
          puts("A");
       else if(total >= 80) puts("B");
       else if(total >= 70) puts("C");
       else if(total >= 60) puts("D");
       else puts("F");

    }
    return 0;     
}
