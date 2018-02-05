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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

double nCm(int n,int m)
{
	int k,i,j;
	double c,d;
	c=d=1;
	k=(m>(n-m))?m:(n-m);
	for(j=1,i=k+1;(i<=n);i++,j++)
	{
		c*=i;
		d*=j;
		if( !fmod(c,d) && (d!=1) )
        {
           c/=d;
           d=1;
        }
	}
	return c;
}

int main()
{
    int n,m;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m+n==0)break;
        printf("%.0lf\n",nCm(m,n));    
    }
    return 0;
}
