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
#define M 1000007
LL a[M];
//5400581
int main()   
{
    LL k,c;
    int n,cas;
    scanf("%d",&cas);
    F(z,cas)
    {
          scanf("%lld%lld%d%lld",&k,&c,&n,&a[0]);
          for(int i=1;i<n;i++)
             a[i]=(k*a[i-1]+c)%1000007LL;
          LL s=0;
          long start=clock();
          for(int i=0;i<n;i++)
             for(int j=i+1;j<n;j++)
               s+=abs(a[i]-a[j]);
          s=abs(s);
          printf("%lld %ld\n",s,clock()-start);
    }
    return 0;
}
