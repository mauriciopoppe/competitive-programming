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
int v[2000];
int main(){
    while(scanf("%d", &v[0]) && v[0]){
        int n = 1, mn = v[0];
        while(scanf("%d", &v[n]) && v[n]){
            mn = min(mn, v[n++]);
        }
        F(i, n) v[i] -= mn;
        sort(v, v + n);
        int gcd = v[n - 1];
        for(int i = n - 1; i >= 1; --i)
            gcd = __gcd(gcd, v[i]);
        printf("%d\n", gcd);
    }
    return 0;
}
