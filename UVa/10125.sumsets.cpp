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

int main()
{	
	int n;
	while(scanf("%d", &n) && n)
	{
		vector<int> v(n);
		map<int, bool> m;
		for(int i = 0; i < n; ++i)
			scanf("%d", &v[i]),
			m[v[i]] = 1;
		sort(ALL(v));
		int f = -1000000000;
		for(int i = n - 1; i >= 0; --i)
		{
			for(int x = 0; x < n; ++x)
				if(x == i) continue;
		   	    else
					for(int y = x + 1; y < n; ++y)
						if(y == i) continue;
						else
							for(int z = y + 1; z < n; ++z)
							   if(z == i) continue;
							   else
								   if(v[i] == v[x] + v[y] + v[z])
								   {
									  f = v[i]; goto end;
								   }
		}
		end:
		if(f == -1000000000)
		  puts("no solution");
		else
		  printf("%d\n", f);
	}
	return 0;
}
