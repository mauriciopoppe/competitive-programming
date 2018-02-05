/*
 * dream.cpp
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
int v[100005];
int main(){
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF){
		for(int i = 0; i < n; ++i)
			scanf("%d", &v[i]);

		int total = 0;
		map<int, bool> taken;
		vector<vector<int> > pos_first(n);
		for(int i = 0; i < min(n, k); ++i){
			if(taken.find(v[i]) == taken.end())
				taken[v[i]] = 1,
				pos_first[i].push_back(v[i]);
		}
		for(int i = k; i < n; ++i){
			TR(pos_first[i - k], it)
				++total, taken.erase(*it);
			if(taken.find(v[i]) == taken.end())
				taken[v[i]] = 1,
				pos_first[i].push_back(v[i]);
		}
		total += taken.size();
		printf("%d\n", total);
	}
	return 0;
}
