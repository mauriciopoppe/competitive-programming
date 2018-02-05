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
	int empty, found, need;
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d%d%d", &empty, &found, &need);
		empty += found;
		int drank = 0;
		while(empty >= need)
		{
			drank += (empty / need);
			empty = empty / need + empty % need;
		}
		printf("%d\n", drank);
	}	
	return 0;
}
