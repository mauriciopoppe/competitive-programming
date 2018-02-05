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
double path[100];
double dist[100];
double cost[100];
double total_capacity;
double mpg;
double min_price;
int stations;

void bt(int i, double capacity, double total_cost)
{
	if(total_cost > min_price)
		return;
	if(i == stations)
		min_price = total_cost;
	else
	{
		if(capacity * mpg >= dist[i])
			bt(i + 1, capacity - dist[i] / mpg, total_cost);
		else
		{
			double to_fill = total_capacity - capacity;
			bt(i + 1, total_capacity, total_cost + round(to_fill * cost[i]) / 100.0 + 2.00);
		}
		
		//maybe it's better to fill the tank if possible
		if(capacity * 2 <= total_capacity)
		{
			double to_fill = total_capacity - capacity;
			bt(i + 1, total_capacity, total_cost + round(to_fill * cost[i]) / 100.0 + 2.00);
		}
	}		
}

int main()
{		
	int cas = 1;
	while(scanf("%lf", &path[99]) && path[99] != -1)
	{
		scanf("%lf%lf%lf%d", &total_capacity, &mpg, &cost[0], &stations);
		path[0] = 0;
		for(int i = 1; i <= stations; ++i)
		{
			scanf("%lf%lf", &path[i], &cost[i]);
			dist[i - 1] = path[i] - path[i - 1];
		}		
		path[++stations] = path[99];
		dist[stations - 1] = path[stations] - path[stations - 1];
		
		min_price = 1e10;
		bt(0, total_capacity, cost[0]);
		printf("Data Set #%d\n", cas++);
		printf("minimum cost = $%.2lf\n", min_price);
	}
	return 0;
}
