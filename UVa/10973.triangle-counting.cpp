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
bool g[3001][3001];

int main()
{	
	int cas;
	int nodes, edges, x, y;
	scanf("%d", &cas);
	while(cas--)
	{
		memset(g, 0, sizeof g);
		scanf("%d%d", &nodes, &edges);
		for(int i = 0; i < edges; ++i)
			scanf("%d%d", &x, &y),
			g[x][y] = g[y][x] = 1;
		int total = 0;
		for(int i = 1; i <= nodes; ++i)
			for(int j = i; j <= nodes; ++j)
				if(g[i][j])
				{
					for(int k = j + 1; k <= nodes; ++k)
						if(g[j][k] && g[k][i])
							++total;
				}
		printf("%d\n", total);
	}
	return 0;
}
