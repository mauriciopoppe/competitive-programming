#include<stdio.h>
#include<stdlib.h>
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
LL v[1000];
int main()
{	
	int n;
	int cas = 1;
	while(scanf("%d", &n) != EOF)
	{
		LL mx = 0;
		for(int i = 0; i < n; ++i)
			scanf("%lld", &v[i]);
		for(int i = 0; i < n; ++i)
		{
			LL t = v[i];
			mx = max(t, mx);
			for(int j = i + 1; j < n; ++j)
				t *= v[j], mx = max(t, mx);
		}
		printf("Case #%d: The maximum product is %lld.\n\n", cas++, mx);
	}		
	return 0;
}
