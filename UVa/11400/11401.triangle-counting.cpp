/*
 * triangle_counting.cpp
 *
 *  Created on: Jul 20, 2012
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
#define M 1000000
LL dp[M + 1];
int main(){
	// precalc
	dp[3] = 0;
	for(int i = 4; i <= M; ++i){
		dp[i] = dp[i - 1];
		if(i & 1){
			LL n = (i - 3) >> 1LL;
			dp[i] += n * n + n;
		}
		else{
			LL n = (i - 1) >> 1LL;
			dp[i] += n * n;
		}
	}
	int n;
	while(scanf("%d", &n) && n >= 3){
		printf("%lld\n", dp[n]);
	}
	return 0;
}
