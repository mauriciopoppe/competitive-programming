/*
 * Author: mauricio
 * Date: Mar 9, 2012
 * Problem: 10094 - Place the Guards.cpp
 */
#include<cstdio>
#include<cstdlib>
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
int v[10000];

int test(int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < i; ++j)
			if(abs(i - j) == abs(v[j] - v[i]))
				return 0;
	}
	return 1;
}

int main()
{
	int n;

	while(scanf("%d", &n) != EOF)
	{
		//6 * k + 2 = n
		//k = (n - 2) / 6
		if(n <= 3)
		{
			puts("Impossible");
			continue;
		}
		int k1 = (n - 2) / 6;
		int k2 = (n - 3) / 6;
		if(6 * k1 + 2 == n || 6 * k2 + 3 == n)
		{
			int k;
			if(6 * k1 + 2 == n) k = k1;
			if(6 * k2 + 3 == n) k = k2;
			int size = 0;

			//print even numbers
			for(int i = 2 * k + 2; i <= n; i += 2)
				v[size++] = i;
			for(int i = 2; i <= 2 * k; i += 2)
				v[size++] = i;

			int n_odd = size;
			for(int i = 1; i <= n; i += 2)
				v[size++] = i;

			while(!test(size))
			{
				int temp = v[size - 1];
				for(int i = size - 1; i > n_odd; --i)
					v[i] = v[i - 1];
				v[n_odd] = temp;
			}

			for(int i = 0; i < size; ++i)
			{
				if(i) putchar(' ');
				printf("%d", v[i]);
			}
			NL;
			continue;
		}
		int size = 0;
		for(int i = 2; i <= n; i += 2)
			v[size++] = i;
		for(int i = 1; i <= n; i += 2)
			v[size++] = i;
		for(int i = 0; i < size; ++i)
		{
			if(i) putchar(' ');
			printf("%d", v[i]);
		}
		NL;
	}
	return 0;
}
