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
    int r,n,cas=1;
    while(scanf("%d%d",&r,&n))
    {
         if(n+r==0)break;
         printf("Case %d: ",cas++);
         if(r>n+26*n){printf("impossible\n");continue;}
         if(n>=r){printf("0\n");continue;}
         int left=r-n;
         //printf("left %d\n",left);
         printf("%d\n",(int)(ceil)((double)left/(double)n));
    }
    return 0;
}
