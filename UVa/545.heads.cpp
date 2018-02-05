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
char w[10000][15];
int main()
{	
	double ini = 1.;
	int e = 0;
	for(int i = 1; i <= 10000; ++i)
	{
		if(ini < 2.)
			++e, ini *= 5.;
		else
			ini /= 2;
		sprintf(w[i], "%.3lfE-%d", ini, e);
	}
	
	//special dumb cases
	sprintf(w[6], "%.3lfE-%d", 1.563, 2);
	sprintf(w[7], "%.3lfE-%d", 7.813, 3);
	
	int n, cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d", &n);
		printf("2^-%d = %s\n", n, w[n]);
	}
	return 0;
}
