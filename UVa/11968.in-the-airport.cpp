/*
 * in_the_airport.cpp
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
	int i, j, testcase, t, n, m, k, ans;
	long long sum;
	int cake[1000], drink[1000];
	double average, dif, nowdif;
	scanf("%d",&testcase);
	for(t = 1; t <= testcase; t++){
		scanf("%d %d %d",&n,&m,&k);
		sum = 0;
		for(i = 0; i < m; i++){
			scanf("%d", &cake[i]);
			sum += cake[i];
		}
		for(i = 0; i < k; i++){
			scanf("%d", &drink[i]);
			sum += drink[i];
		}
		for(i = m + k; i < n; i++){
			scanf("%d", &j);
			sum += j;
		}

		average = (double)sum / n;

		printf("Case #%d:",t);
		dif = 2147483647.0;
		for(i = 0; i < m; i++){
			nowdif = fabs(cake[i] - average);
			if(nowdif < dif){
				dif = nowdif;
				ans = cake[i];
			}
			else if(nowdif == dif){
				if(cake[i] < ans)
					ans = cake[i];
			}
		}
		printf(" %d", ans);
		dif=2147483647.0;
		for(i = 0; i < k; i++){
			nowdif = fabs(drink[i] - average);
			if(nowdif < dif){
				dif = nowdif;
				ans = drink[i];
			}
			else if(nowdif == dif){
				if(drink[i] < ans) ans = drink[i];
			}
		}
		printf(" %d\n", ans);
	}
	return 0;
}



