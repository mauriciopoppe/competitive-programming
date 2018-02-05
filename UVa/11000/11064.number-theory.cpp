/*
 * Author: mauricio
 * Date: Mar 6, 2012
 */
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

/*
 * Returns the number of numbers where gcd(a, b) == 1 and a < b
 */
int euler_totient(int n)
{
	if(n == 1) /* 1 has no numbers below it*/
		return 0;

	int remainder = n;

	if(n % 2 == 0)
	{
		remainder -= remainder >> 1;
		while(n % 2 == 0)
			n >>= 1;
	}

	for(int i = 3; i * i <= n; i += 2)
	{
		if(n % i == 0)
		{
			remainder -= remainder / i;
			while(n % i == 0)
				n /= i;
		}
	}
	if(n > 1)
		remainder -= remainder / n;
	return remainder;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
		printf("%d\n", n - euler_totient(n));
	return 0;
}
