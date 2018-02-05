/*
 * csumd.cpp
 *
 *  Created on: Jul 9, 2012
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
typedef vector<vector<LL> > vii;

#define MOD 1000000007
vii matrix_multiplication(vii m1, vii m2){
	vii m;
	m.push_back(vector<LL>(2));
	m.push_back(vector<LL>(2));

	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j){
			m[i][j] = 0;
			for(int k = 0; k < 2; ++k)
				m[i][j] = (m[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;
		}
	return m;
}

void print(vii m){
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j)
			printf("%lld ", m[i][j]);
		NL;
	}

}

int main(){
	map<int, LL> m;
	int cas;
	LL n;
	scanf("%d", &cas);


	//precalc mat values
	vector<vii> solved(1);

	vector<vector<LL> > mat;
	mat.push_back(vector<LL>(2));
	mat.push_back(vector<LL>(2));
	mat[0][0] = mat[0][1] = 2;
	mat[1][0] = 1;
	mat[1][1] = 0;
	solved.push_back(mat);
	for(int i = 1; i <= 1000000000; i <<= 1){
		mat = matrix_multiplication(mat, mat);
		solved.push_back(mat);
	}

	while(cas--){
		scanf("%lld", &n);

		if(m[n]) {printf("%lld\n", m[n]); continue;}
		if(n == 1) puts("1");
		else if(n == 2) puts("3");
		else{
			vector<vector<LL> > res;
			res.push_back(vector<LL>(2));
			res.push_back(vector<LL>(2));
			res[0][0] = res[1][1] = 1;
			res[0][1] = res[1][0] = 0;

			n -= 2;
			int j = 1;
			for(LL i = 1; i <= n; i <<= 1, ++j)
				if(i & n)
					res = matrix_multiplication(solved[j], res);
			printf("%lld\n", m[n] = ((res[0][1] + (res[0][0] * 3) % MOD) % MOD));
		}
	}

	return 0;
}
