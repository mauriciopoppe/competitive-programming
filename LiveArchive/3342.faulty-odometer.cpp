/*
 * solitaire.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: Mauricio Poppe -- maurizzzio@maurizzzio.com
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
using namespace std;

int main(){
    map<int, int> m;
    m[0] = 0;
    m[1] = 1;
    int start = 1;
    int pow10 = 10;
    for(int i = 2; i <= 10; ++i){
        int new_start = start * 10;
        m[new_start] = 9 * m[start] + start * 10;
        start = new_start;
    }
    int n;
    while(scanf("%d", &n) && n){
        int total = 0;
        int mult = 1;
        int cp_n = n;
        while(n){
            // get last non zero digit
            int last = n % (mult * 10) / mult;
            //printf("%d\n", last);
            if(last < 4)
                total += last * m[mult / 10];
            else
                total += 4 * m[mult / 10] + (last - 5) * m[mult / 10] + mult;
            n /= mult * 10;
            n *= mult * 10;
            mult *= 10;
        }
        printf("%d: %d\n", cp_n, cp_n - total);
    }
    return 0;
}
