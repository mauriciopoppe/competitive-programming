/*
 * graysc.cpp
 *
 *  Created on: Jul 10, 2012
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
typedef unsigned long long LL;
#define M 100005

LL v[M];
typedef map<int, vector<int> > mii;

int solve(mii &pos){
	TR(pos, it){
		vector<int> v = it->second;
		if(v.size() < 2)
			continue;
		if(v.size() >= 3)
			return 1;
		int left = v[0];
		int right = v[1];
		if(left + 1 != right)
			return 1;
	}
	return 0;
}

int big_four(map<LL, int> &cnt){
	TR(cnt, it)
		if(it->second >= 4)
			return 1;
	return 0;
}

int main(){
	
	int n;
	while(scanf("%d", &n) != EOF){
		map<int, vector<int> > pos;
		map<LL, int > cnt;
		for(int i = 0; i < n; ++i){
			scanf("%llu", &v[i]);
			++cnt[v[i]];
			if(i){
				LL xor_val = v[i] ^ v[i - 1];
				LL shift = 1;
				int diff = -1;
				for(int j = 0; j < 64; ++j, shift <<= 1LL){
					if(xor_val & shift){
						diff = j;
						break;
					}
				}
				if(pos.find(diff) == pos.end())
					pos[diff] = vector<int>();
				pos[diff].push_back(i - 1);
			}
		}

		if(solve(pos) || big_four(cnt)) puts("Yes");
		else puts("No");

	}
	return 0;
}

