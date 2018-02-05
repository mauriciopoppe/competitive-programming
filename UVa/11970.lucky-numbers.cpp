/*
 * lucky.cpp
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
#define M 1000000000LL
LL sq[100000];
int res[100000];
int main(){
	for(LL i = 1; i * i <= M; ++i)
		sq[(int)i] = i * i;
	int cas, N;
	scanf("%d", &cas);
	F(z, cas){
		scanf("%d", &N);
		printf("Case %d:", z + 1);
		int j = 0;
		for(int i = 1; sq[i] < N; ++i){
			int X = N - sq[i];
			if(X % i == 0)
				res[j++] = X;
		}
		for(int i = j - 1; i >= 0; --i)
			printf(" %d", res[i]);
		NL;
	}
	return 0;
}
