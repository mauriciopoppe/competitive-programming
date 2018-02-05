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
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int main()
{
 	int a[51];
 	int t,p,c;
 	int cas=1;
 	while(scanf("%d",&t) && t)
 	{
         p=c=0;                
	 	 F(i,t) scanf("%d",&a[i]),p+=a[i];
	 	 p/=t;
	 	 F(i,t) c+=(a[i]>p?a[i]-p:0);
	 	 printf("Set #%d\nThe minimum number of moves is %d.\n",cas++,c);
         
    }
    return 0;
}
