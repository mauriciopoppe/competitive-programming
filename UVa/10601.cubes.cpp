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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int main()
{
    int x,y,z,n;
    while(scanf("%d",&n) && n)
    {
         bool f=0;
         for(y=0;y<60;y++)
         {
              z=y*y*y+n;
              x=(int)(pow(z,1.0/3.0)+0.5);
              if(x*x*x==z){f=1;break;}
         }
         if(f && y>0 && x>0)printf("%d %d\n",x,y);
         else printf("No solution\n");
    }
    return 0;
}
