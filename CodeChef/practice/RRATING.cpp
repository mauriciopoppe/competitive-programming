/*
 * rrating.cpp
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
typedef map<int, int> mii;

void move_last(mii &from, mii &to){
	mii::reverse_iterator it = from.rbegin();
	--from[it->first];
	++to[it->first];
	if(from[it->first] == 0){
		//delete
		from.erase(it->first);
	}
}

void move_first(mii &from, mii &to){
	mii::iterator it = from.begin();
	--from[it->first];
	++to[it->first];
	if(from[it->first] == 0){
		//delete
		from.erase(it->first);
	}
}

int main(){
	int n;
	int op, number;
	int total_left = 0, total_right = 0;
	int total = 0;
	map<int, int> two_thirds;
	map<int, int> one_third;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &op);
		if(op == 1){
			scanf("%d", &number);
			if(total < 3){
				if(total_left < 2){		// insert first two elements
					++two_thirds[number];
					++total_left;
				}
				else if(total_left == 2){
					if(number <= two_thirds.rbegin()->first){	// insert left
						++two_thirds[number];
						move_last(two_thirds, one_third);
					}
					else
						++one_third[number];
					++total_right;
				}
			}
			else{
				int size_right = (total + 1) / 3;			// new size right
				int size_left = total - size_right + 1;			// new size left
				if(number <= two_thirds.rbegin()->first){	// insert left
					++two_thirds[number];
					++total_left;
				}
				else{	//insert right
					++one_third[number];
					++total_right;
				}

//				printf("SIZES REQ %d %d\n", size_left, size_right);
//				printf("SIZES %d %d\n", total_left, total_right);

				if(total_right == size_right + 1){
					// right has 1+ element
					move_first(one_third, two_thirds);
					--total_right;
					++total_left;
				}
				else if(total_left == size_left + 1){
					// left has 1+ element
					move_last(two_thirds, one_third);
					--total_left;
					++total_right;
				}
			}
			++total;
//			puts("LEFT");
//			TR(two_thirds, it)
//				printf("%d->%d\n", it->first, it->second);
//			puts("RIGHT");
//			TR(one_third, it)
//				printf("%d->%d\n", it->first, it->second);
		}
		else{
			if(total_right == 0)
				puts("No reviews yet");
			else
				printf("%d\n", (one_third.begin())->first);
		}
	}
	return 0;
}
