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
int v[55];
int main()
{
    int t,n;
    scanf("%d",&t);
    F(q,t)
    {
          scanf("%d",&n);
          F(i,n)scanf("%d",&v[i]);
          int h=0,l=0;
          FOR(i,1,n)
             if(v[i]>v[i-1])h++;
             else if(v[i]<v[i-1])l++;
          printf("Case %d: %d %d\n",q+1,h,l);
    }
    return 0;
}
