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
	double v0, v;
	double a[1000005];
	while(scanf("%lf%lf", &v, &v0))
	{
		if(v == 0 && v0 == 0)
		   break;
		int size = 0;
		for(int i = 1; v / (double)(i) >= v0; ++i)
		{
			double t = v / (double)(i);
			a[size++] = 0.3 * sqrt(t - v0) * i;
			//printf("> %.25lf\n", a[size - 1]);
		}
		
		double mx = 0;
		for(int i = 0; i < size; ++i)
		   mx = max(mx, a[i]);
		int best = -1, c = 0;
		for(int i = 0; i < size; ++i)
		   if(fabs(a[i] - mx) < 1e-7)
		      ++c, best = i + 1;
		if(mx == 0)
		   puts("0");
		else
		{
			if(c > 1)
			   puts("0");
			else
			   printf("%d\n", best);	
		}
	}
	return 0;
}
