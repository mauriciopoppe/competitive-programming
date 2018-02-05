/*
 * prime_generator.cpp
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

#define M 32000
bitset<M+500> b;
int primes[M];
int total_primes;

void init(){
	for(int i = 4; i < M; i += 2)
		b[i] = 1;
	for(int i = 3; i * i < M; i += 2)
		if(!b[i])
			for(int j = i * i, inc = 2 * i; j < M; j += inc)
				b[j] = 1;
	total_primes = 0;
	primes[total_primes++] = 2;
	for(int i = 3; i < M; i += 2)
		if(!b[i])
			primes[total_primes++] = i;
}

int check_prime(int i){
	if(i == 1)
		return 0;
	for(int j = 0; primes[j] * primes[j] <= i; ++j)
		if(i % primes[j] == 0)
			return 0;
	return 1;
}

int main(){
	init();
	int cas, left, right;
	scanf("%d", &cas);
	while(cas--){
		scanf("%d%d", &left, &right);
		for(int i = left; i <= right; ++i){
			//check if i is prime
			if(check_prime(i))
				printf("%d\n", i);
		}
		if(cas)NL;
	}
	return 0;
}
