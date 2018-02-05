/*
 * magic_formula.cpp
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

int main(){
	int a, b, c, d, L;
	while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &L) &&
			a + b + c + d + L != 0){
		int total = 0;
		for(int x = 0; x <= L; ++x){
			//printf("%d\n", 2 * x * a + b * x + c);
			if((x * x * a + b * x + c) % d == 0)
				++total;
		}
		printf("%d\n", total);
	}
	return 0;
}



