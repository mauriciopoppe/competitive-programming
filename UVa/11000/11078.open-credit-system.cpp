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
int v[1000000];
int main()
{	
	int cas;
	int n;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		int mx = -1000000, mn;
		int best = -1000000;
		for(int i = 0; i < n - 1; ++i)
		{
			if(v[i] > mx)
				mx = v[i], 
				mn = v[i + 1],
				best = max(best, mx - mn);
			else if(v[i + 1] < mn)
				mn = v[i + 1],
				best = max(best, mx - mn);				
		}
		printf("%d\n", best);
	}				
	return 0;
}
