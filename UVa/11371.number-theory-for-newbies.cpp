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
    char w[50];
    LL n,m;
    while(scanf("%lld",&m)!=EOF)
    {
          sprintf(w,"%lld",m);
          int s=strlen(w);
          sort(w,w+s);
          reverse(w,w+s);
          m=atoll(w);
          
          reverse(w,w+s);
          if(w[0]=='0')
          {
             int i=1;          
             while(i<s && w[i]=='0')++i;
             swap(w[0],w[i]);
          }
          n=atoll(w);          
          printf("%lld - %lld = %lld = 9 * %lld\n",m,n,m-n,(m-n)/9);
    }
    return 0;
}
