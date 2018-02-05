/*
 * yet_another_number_sequence.cpp
 *
 *  Created on: Jul 18, 2012
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
typedef vector<int> vi;
typedef vector<vi> vii;

int m;

vii matrix_mult(vii x, vii y){
	vii res; res.push_back(vi()); res.push_back(vi());
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j){
			res[i].push_back(0);
			for(int k = 0; k < 2; ++k)
				res[i][j] += x[i][k] * y[k][j];
			// keep just last m digits
			res[i][j] %= 10000;
		}
	return res;
}

int main(){
	int t;
	int a, b, n;
	int MOD[5] = {0, 10, 100, 1000, 10000};
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &a, &b, &n, &m);
		vii I; I.push_back(vi()); I.push_back(vi());
		I[0].push_back(1);I[0].push_back(0);
		I[1].push_back(0);I[1].push_back(1);
		
		vii M; M.push_back(vi()); M.push_back(vi());
		M[0].push_back(1);M[0].push_back(1);
		M[1].push_back(1);M[1].push_back(0);
		
		n -= 1;
		for(int i = 1; i <= n; i <<= 1){
			if(n & i){
				I = matrix_mult(I, M);
			}
			M = matrix_mult(M, M);
		}
		printf("%d\n", (I[0][0] * b + I[0][1] * a) % MOD[m]);
	}
	return 0;
}
