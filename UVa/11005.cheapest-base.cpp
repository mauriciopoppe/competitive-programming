#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
#include <limits>
#include <cfloat>
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
	LL cost[40];
	LL cost_in_base[40];
	int cas, q, k;
	scanf("%d", &cas);
	for(int j = 0; j < cas; ++j)
	{
		if(j)NL;
		for(int i = 0; i < 36; ++i)
			scanf("%lld", &cost[i]);
		printf("Case %d:\n", j + 1);
		scanf("%d", &q);
		for(int z = 0; z < q; ++z)
		{
			scanf("%d", &k);
			memset(cost_in_base, 0, sizeof cost_in_base);
			for(int base = 2; base <= 36; ++base)
			{
				int cp = k;
				while(cp)
				{
					cost_in_base[base] += cost[cp % base];
					cp /= base;
				}
			}
			LL mn = 99999999999999LL;
			for(int base = 2; base <= 36; ++base)
			   mn = min(mn, cost_in_base[base]);
			printf("Cheapest base(s) for number %d:", k);
			for(int base = 2; base <= 36; ++base)
			   if(cost_in_base[base] == mn)
			   		printf(" %d", base);
			NL;
		}
	}				
	return 0;
}
