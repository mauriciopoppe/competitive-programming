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
	int cas, n, i;
	double win;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d%lf%d", &n, &win, &i);
		int mul = 0;
		double res = 0.;
		while(1)
		{
			double k = pow(1.0 - win, (double) (mul * n + i - 1)) * win;
			if(k < 1e-8)
				break;
			res += k;
			++mul;
		}
		printf("%.4lf\n", res);
	}
	return 0;
}
