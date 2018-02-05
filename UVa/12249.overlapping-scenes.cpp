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
	int cas, n;
	scanf("%d", &cas);
	for(int z = 0; z < cas; ++z)
	{
		scanf("%d", &n);
		
		vector<string> name(n);
		vector<string> order(n);
		vector<int> v(n);
		
		for(int i = 0; i < n; ++i)
		{
			cin >> name[i];
			v[i] = i;
		}
		
		sort(ALL(name));
		
		int mn = 1000000;
		
		do{
			for(int i = 0; i < n; ++i)
				order[i] = name[v[i]];
			
			string ini = order[0];
			for(int i = 1; i < n; ++i)
			{
				int size = ini.size(), 
					order_size = order[i].size(),
					start;
					
				if(size < order_size)
					start = 0;
				else
					start = size - order_size;
				
				int total = 0;
				for(int j = start; ini[j]; ++j)
				{
					int k;					
					for(k = 0; ini[k + j]; ++k)
						if(ini[j + k] != order[i][k])
							break;
					if(!ini[k + j])
					{
						total = size - j;
						break;
					}
				}
				
				for(int j = total; order[i][j]; ++j)
					ini += order[i][j];
				
			}
			mn = min((int)ini.size(), mn);
		}while(next_permutation(ALL(v)));
		
		printf("Case %d: %d\n", z + 1, mn);
	}
	return 0;
}
