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
struct num{       
       int n,mod;
       bool operator<(const num &x)const
       {
            if(x.mod!=mod)return mod<x.mod;
            bool evX=!(x.n&1), evN=!(n&1);
            if(evX!=evN)return evX==1;
            if(evX==1)return n<x.n;
            return n>x.n;
       }     
} v[10001];

int main()
{
    //printf("%d\n",-100%3);
    //printf("%d\n",-3%3);    
    int n,m,k;
    while(scanf("%d%d",&n,&m))
    {
         printf("%d %d\n",n,m);
         if(n==0 && m==0)return 0;
         F(i,n)
              scanf("%d",&v[i].n),v[i].mod=v[i].n%m;
         sort(v,v+n);
         F(i,n)printf("%d\n",v[i].n);
    }
    return 0;
}
