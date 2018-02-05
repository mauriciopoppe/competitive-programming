/*
 * palin.cpp
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

typedef pair<int, int> pii;
#define M 1000005
char number[M];
int pal[M];

pii solve(int left, int right){
	pii start(left, 1);
	for(int i = 0; left >= 0; ++i, --left, ++right){
		if(number[left] != number[right]){
			if(number[left] > number[right])
				return pii(left, 0);
			else
				return pii(start.first, 1);
		}
	}
	return start;
}

int main(){
	int cas;
	scanf("%d", &cas);gets(number);
	while(cas--){
		gets(number);
		int size = strlen(number);
		int left, right;
		left = right = (size - 1) / 2;
		if((size & 1) == 0)
			right++;

		pii pos = solve(left, right);
		int carry = 0;
		int i;
		int mx_left = left;

		for(i = 0; left >= 0 || carry; ++i, --left){
			pal[i] = carry;
			carry = 0;
			if(left >= 0)
				pal[i] += number[left] - '0';
			if(pos.first == left)
				pal[i] += pos.second;
			if(pal[i] > 9)
				pal[i] -= 10,
				carry = 1;
		}

//		for(int j = i - 1; j >= 0; --j)
//			printf("%d", pal[j]); NL;
		//printf("%d %d\n", mx_left, i);
		if(size & 1){
			if(i == mx_left + 1){
				for(int j = i - 1; j >= 0; --j)
					putchar(pal[j] + '0');
				for(int j = 1; j < i; ++j)
					putchar(pal[j] + '0');
			}
			else{
				for(int j = i - 1; j >= 1; --j)
					putchar(pal[j] + '0');
				for(int j = 1; j < i; ++j)
					putchar(pal[j] + '0');
			}
		}
		else{
			if(i == mx_left + 1){
				for(int j = i - 1; j >= 0; --j)
					putchar(pal[j] + '0');
				for(int j = 0; j < i; ++j)
					putchar(pal[j] + '0');
			}
			else{
				for(int j = i - 1; j >= 0; --j)
					putchar(pal[j] + '0');
				for(int j = 1; j < i; ++j)
					putchar(pal[j] + '0');
			}
		}
		NL;
	}
	return 0;
}
