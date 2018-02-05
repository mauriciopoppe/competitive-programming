/*
 * Author: mauricio
 * Date: Mar 14, 2012
 * Problem: 868 - Numerical Maze.cpp
 */
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
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

set<int> sol;
int board[1000][1000];
int visited[1000][1000];
int row, col;
int dx[] = {-1, 0, 0, 1}, dy[]= {0, -1, 1, 0};

int check(int &x, int &y)
{
	if(x == row && y >= 0 && y < col)
		return 2;
	if(x >= 0 && y >= 0 && y < col)
		return 1;
	return 0;
}

void bt(int x, int y, int max_level, int current)
{
	//printf("%d %d %d %d\n", x, y, max_level, current);
	int next = current + 1;
	//printf("%d %d\n", next, max_level);
	if(next > max_level)
	{
		//printf("here\n");
		max_level++;
		next = 1;
	}
	//printf("> %d %d %d\n", max_level, next, current);
	for(int i = 0; i < 4; ++i)
	{
		int x1 = x + dx[i], y1 = y + dy[i];
		int k = check(x1, y1);
		if(k == 2 && current == 1)
			sol.insert(y);
		else if(k == 1 && !visited[x1][y1] && board[x1][y1] == current)
		{
			visited[x1][y1] = 1;
			bt(x1, y1, max_level, next);
			visited[x1][y1] = 0;
		}
	}
}

void solve()
{
	int solved = 0, i;
	sol.clear();
	memset(visited, 0, sizeof visited);
	for(i = 0; i < col && !solved; ++i)
	{
		//printf("START = %d\n", i);
		bt(-1, i, 1, 1);
		solved += sol.size();
	}
	printf("%d %d\n%d %d\n", 1, i, row, *sol.begin() + 1);
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d%d", &row, &col);
		for(int i = 0; i < row; ++i)
			for(int j = 0; j < col; ++j)
				scanf("%d", &board[i][j]);
		solve();
		if(cas) putchar(10);
	}
	return 0;
}
