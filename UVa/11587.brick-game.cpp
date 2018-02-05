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
int v[15];
int d[15];
int main()
{
    int cas,n;
    scanf("%d",&cas);
    F(z,cas)
    {
         scanf("%d",&n);   
         memset(d,0,sizeof d);
         F(i,n)scanf("%d",&v[i]);
         F(i,n)
         {
              F(j,n)
                if(i!=j)
                  d[i]+=abs(v[i]-v[j]); 
         }
         int best=-1,mx=IMAX;
         F(i,n)
            if(d[i]<mx){mx=d[i],best=i;}
         printf("Case %d: %d\n",z+1,v[best]);
    }
    return 0;
}
