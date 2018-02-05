/*
 * Author: mauricio
 * Date: Mar 16, 2012
 * Problem: 416 - LED Test.cpp
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

char w[10];
int leds[10][7];
int key[][10] = {{1, 1, 1, 1, 1, 1, 0}, //0
				 {0, 1, 1, 0, 0, 0, 0}, //1
				 {1, 1, 0, 1, 1, 0, 1}, //2
				 {1, 1, 1, 1, 0, 0, 1}, //3
 				 {0, 1, 1, 0, 0, 1, 1}, //4
 				 {1, 0, 1, 1, 0, 1, 1}, //5
				 {1, 0, 1, 1, 1, 1, 1}, //6
				 {1, 1, 1, 0, 0, 0, 0}, //7
				 {1, 1, 1, 1, 1, 1, 1}, //8
				 {1, 1, 1, 1, 0, 1, 1}}; //9
int n;

int test(int start)
{
	int dead[10];
	memset(dead, 0, sizeof dead);
	//printf("start = %d\n", start);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 7; ++j)
		{
			if(leds[i][j] == 1 && key[start - i][j] == 0)
				return 0;
			if(leds[i][j] == 1 && dead[j] == 1)
				return 0;
			if(leds[i][j] == 0 && key[start - i][j] == 1)
				dead[j] = 1;
		}
	}
	return 1;
}

int solve()
{
	for(int i = 9; i + 1 >= n; --i)
		if(test(i))
			return 1;
	return 0;
}

int main()
{
	while(scanf("%d", &n) && n)
	{
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", w);
			for(int j = 0; w[j]; ++j)
				leds[i][j] = w[j] == 'Y' ? 1 : 0;
		}
		if(solve())
			puts("MATCH");
		else
			puts("MISMATCH");
	}
	return 0;
}
