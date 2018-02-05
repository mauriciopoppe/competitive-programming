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
typedef long long LL;
#define M 1000000
bool prime[M + 100];
LL p[M];
int total;
void init(){

    memset(prime, 0, sizeof prime);
    for(int i = 3; i * i <= M; i += 2){
        if(!prime[i])
            for(int j = i * i; j <= M; j += 2 * i)
                prime[j] = 1;
    }
    total = 0;
    p[total++] = 2;
    for(int i = 3; i <= M; i += 2)
        if(!prime[i])
            p[total++] = i;
}

int total_primes(LL n){
    LL k = 0;
    for(int i = 0; i < total && p[i] * p[i] <= n; ++i){
        LL cp = p[i] * p[i];
        while(1){
            if(cp <= n) ++k;
            else break;
            cp *= p[i];
        }
    }
    return k;
}

int main()
{
    int n;
    LL a, b;
    init();
    scanf("%d", &n);
    while(n--){
        scanf("%lld%lld", &a, &b);
        LL L = total_primes(a - 1LL);
        LL R = total_primes(b);
        //printf("%lld %lld\n", L, R);
        printf("%lld\n", total_primes(b) - total_primes(a - 1LL));
    }
    return 0;
}
