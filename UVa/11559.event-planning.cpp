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
#define INF 1000000000
int main()
{
    int n,b,h,w,cost,x;
    int ht[20];
    while(scanf("%d%d%d%d",&n,&b,&h,&w)!=EOF)
    {
         int mn=INF;
         F(i,h)
         { 
              scanf("%d",&cost);
              x=n*cost;
              F(j,w)
                 scanf("%d",&ht[j]); 
              F(j,w)
                 if(ht[j]>=n)
                     if(x<mn && x<=b){mn=x;break;}
         }
         if(mn==INF)printf("stay home\n");
         else printf("%d\n",mn);
    }
    return 0;
}
