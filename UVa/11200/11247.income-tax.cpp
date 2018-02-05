/*
 * income_tax.cpp
 *
 *  Created on: Jul 17, 2012
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

LL m, x;

int test_income(LL v){
	//printf("%lld %lld\n", 100 * v - v * x, 100 * m - 100);
	return 100 * v - v * x >= 100 * m - 100;
}

int main(){
	while(scanf("%lld%lld", &m, &x) && m + x != 0){
		if(x == 0 || m == 1 || x == 100){
			puts("Not found");
			continue;
		}
		LL v = ceil((double)(m + 1) / (double)(1.0 - (x / 100.0)));
		while(test_income(v))
			v--;
		if(v >= m)
			printf("%lld\n", v);
		else
			puts("Not found");
	}
	return 0;
}



