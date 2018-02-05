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
int n, min_candies;
int b[10][10];
bool v[10];

void bt(int k, int sum)
{
	if(k == n)
		min_candies = min(min_candies, sum);
	else
	{
		for(int i = 0; i < n; ++i)
			if(!v[i])
			{
				v[i] = 1;
				bt(k + 1, sum + b[k][i]);
				v[i] = 0;
			}
	}
}

int main()
{	
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &b[i][j]);
		min_candies = 1000000000;
		for(int i = 0; i < n; ++i)
			v[i] = 0;
		bt(0, 0);
		printf("%d\n", min_candies);
	}
	return 0;
}
