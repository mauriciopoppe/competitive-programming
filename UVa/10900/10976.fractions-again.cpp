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
	int n;
	while(scanf("%d", &n) != EOF)
	{
		//1 / n = 1 / k + 1 / i
		int size = 0;
		int v[10005][3];
		for(int i = n + 1; i <= n * 2; ++i)
		{
			int den = i * n;
			int num = den / n - den / i;
			int gcd = __gcd(num, den);
			den /= gcd;
			num /= gcd;
			if(num == 1)
			   v[size][0] = i,
			   v[size++][1] = den;	
		}
		printf("%d\n", size);
		for(int i = 0; i < size; ++i)
		   printf("1/%d = 1/%d + 1/%d\n", n, v[i][1], v[i][0]);
	}	
	return 0;
}
