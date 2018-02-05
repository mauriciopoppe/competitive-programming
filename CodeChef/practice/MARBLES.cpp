/*
 * marbles.cpp
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

LL nCk(LL n, LL k){
	if(k > n) return 0;
	if(k * 2 > n) k = n - k;
	if(k == 0) return 1;

	LL result = n;
	for( int i = 2; i <= k; ++i ) {
		result *= (LL)(n - i + 1);
		result /= (LL)i;
	}
	return result;
}

int main(){
	int cas;
	LL n, k;
	scanf("%d", &cas);
	while(cas--){
		scanf("%lld%lld", &n, &k);
		LL total = 1;
		n -= k;
		if(n != 0)
			total = nCk(n + k - 1, n);
		printf("%lld\n", total);
	}
	return 0;
}
