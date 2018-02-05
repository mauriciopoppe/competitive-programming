/*
 * billard_bounces.cpp
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
#define PI ((2.0) * acos(0))
double to_rad(double x){
	return x * PI / 180.0;
}

int main(){
	double width, height, v, a, s;
	while(scanf("%lf%lf%lf%lf%lf", &width, &height, &v, &a, &s) &&
			width + height + v + a + s != 0){
		double aceleration = -v / s;
		double hyp = v * s + 0.5 * aceleration * s * s;
		double dx = fabs(cos(to_rad(a)) * hyp);
		double dy = fabs(sin(to_rad(a)) * hyp);
		//printf("%lf %lf\n", dx, dy);

		int touch_top = 0;
		double current_top = height * 0.5;

		while(dy >= current_top){
			touch_top++;
			current_top += height;
		}

		int touch_left = 0;
		double current_left = width * 0.5;
		while(dx >= current_left){
			touch_left++;
			current_left += width;
		}
		printf("%d %d\n", touch_left, touch_top);
	}
	return 0;
}
