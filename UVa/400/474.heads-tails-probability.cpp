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
char w[1000001][15];
int main()
{	
	double ini = 1.;
	int e = 0;
	for(int i = 1; i <= 1000000; ++i)
	{
		if(ini < 2.)
			++e, ini *= 5.;
		else
			ini /= 2;
		sprintf(w[i], "%.3lfe-%d", ini, e);
	}
	
	int n;
	while(scanf("%d", &n) != EOF)
		printf("2^-%d = %s\n", n, w[n]);
	return 0;
}
