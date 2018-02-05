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
int p2[250];
int v[50001][3];
int main()
{	
	int size = 0, t;
	for(; size * size <= 50000; ++size)
		p2[size] = size * size;
	memset(v, -1, sizeof v);
	for(int i = 0; i < size; ++i)
		for(int j = 0; j < size; ++j)
			for(int k = 0; k < size; ++k)
				if((t = p2[i] + p2[j] + p2[k]) <= 50000 && v[t][0] == -1)
					v[t][0] = i,
					v[t][1] = j,
					v[t][2] = k;
	int cas;
	int n;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d", &n);
		if(v[n][0] != -1)
			printf("%d %d %d\n", v[n][0], v[n][1], v[n][2]);
		else
		    puts("-1");
	}
	return 0;
}
