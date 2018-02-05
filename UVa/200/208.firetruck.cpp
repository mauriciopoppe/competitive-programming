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
#define INF 999999
bool g[25][25];
bool discovered[50];
int d[25][25];
int path[100], total;
int dest;

void dfs(int i, int n)
{
	if(i == dest)
	{
		for(int j = 0; j < n; ++j)
		{
			if(j) putchar(' ');
			printf("%d", path[j]);
		}
		NL;
		++total;
	}
	else
	{
		for(int j = 1; j <= 21; ++j)
			if(i != j && g[i][j] && !dis[j])
			{
				dis[j] = 1;
				path[n] = j;
				dfs(j, n + 1);
				dis[j] = 0;
			}
	}
}

void check_reach(int i)
{
	if(i == 1)
		good[i] = 1;
	else
	{
		for(int j = 0; j <= 21; ++j)
	}
}

int main()
{	
	int x, y;
	int cas = 1;
	while(scanf("%d", &dest) != EOF)
	{
		memset(g, 0, sizeof g);
		while(scanf("%d%d", &x, &y) && x)
			g[x][y] = g[y][x] = 1;
			
		//floyd warshall
		floyd_warshall();	
			
		memset(dis, 0, sizeof dis);
		path[0] = 1;
		dis[1] = 1;
		total = 0;
		printf("CASE %d:\n", cas++);
		dfs(1, 1);
		printf("There are %d routes from the firestation to streetcorner %d\n", total, dest);
	}
	return 0;
}
