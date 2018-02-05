#include<cstdio>
#include<cstdlib>
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
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define M 100
int sm[M + 10], xr[M + 10];
int x[M + 10], y[M + 10];
int carry[M + 10];
void bin(ULL n, int a[]){
    int i = 0; 
    while(n){
        a[i++] = n & 1;
        n >>= 1;
    }
}

ULL dec(int a[]){
	int i = 0;
    ULL t = 1;
	ULL s = 0; 
    while(i < M){
        if(a[i++]) s += t;
        t *= (ULL)2;
    }
    return s;
}

int main()
{
    ULL A, B;
    int cnt = 0;
    while(cin >> A >> B) {
		if(cnt) NL; cnt = 1;
	    memset(sm, 0, sizeof sm);
	    memset(xr, 0, sizeof xr);
	    memset(carry, 0, sizeof carry);
        bin(A, sm);
        bin(B, xr);
		
		F(i, 10) printf("%d", sm[i]); NL;
		F(i, 10) printf("%d", xr[i]); NL;
		
		F(i, M)
		    if(sm[i] != xr[i])
				carry[i] = 1;
		int possible = 1;
		F(i, M){
			if (carry[i]){
				// different
			    if(xr[i]) {
					x[i] = 0;
					y[i] = 1;
			    } else {
					if(carry[i + 1]){
						x[i] = 1;
						y[i] = 1;
					} else {					
						x[i] = 0;
						y[i] = 0;
					}
			    }
			} else {
				// equal
				if(sm[i]){
					x[i] = 0;
					y[i] = 1;
				} else{
					if (carry[i + 1]){
						x[i] = y[i] = 1;
					} else {
						x[i] = y[i] = 0;
					}
				}
			}
		}
		
		F(i, 10) printf("%d", x[10 - i - 1]); NL;
		F(i, 10) printf("%d", y[10 - i - 1]); NL;
		
		ULL X = dec(x);
		ULL Y = dec(y);
		
		if(X + Y == A) printf("%llu %llu\n", X, Y);
		else puts("-1");
    }
    return 0;
}

