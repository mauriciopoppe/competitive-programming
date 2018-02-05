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

int getRepetitions(int n, int p)
{
    LL c=0,i;
    for(i=p;i<=n;i*=p)
    		c+=n/i;
    return c;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    int m,n;
    F(q,t)
    {
        cin>>m>>n;  
        printf("Case %d:\n",q+1);
        LL h=getRepetitions(n,m);
        //printf("%d\n",h);
        if(h)printf("%lld\n",h);
        else printf("Impossible to divide\n"); 
    }
    return 0;
}
