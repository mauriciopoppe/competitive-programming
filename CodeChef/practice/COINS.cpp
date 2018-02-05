/*
 * bytelandian_gold_coins.cpp
 *
 *  Created on: Jul 8, 2012
 *      Author: mauricio
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
#include<time.h>
#include<limits.h>
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
#define PI acos(-1)
#define EPS 1e-8
typedef long long LL;

map<int, LL> m;

LL solve(int n){
	if(n <= 2) return n;
	if(!m[n]){
		//printf("%d\n", n);
		LL exchange = solve(n / 2) + solve(n / 3) + solve(n / 4);
		m[n] = max((LL)n, exchange);
	}
	return m[n];
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		printf("%lld\n", solve(n));
	}
	return 0;
}
