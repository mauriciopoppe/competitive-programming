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
#define MX 1000
bool prime[MX + 100];
int M[MX * MX + 100], mu[MX * MX + 100];
LL p[MX];
int total;
void init(){

    memset(prime, 0, sizeof prime);
    for(int i = 3; i * i <= MX; i += 2){
        if(!prime[i])
            for(int j = i * i; j <= MX; j += 2 * i)
                prime[j] = 1;
    }
    total = 0;
    p[total++] = 2;
    for(int i = 3; i <= MX; i += 2)
        if(!prime[i])
            p[total++] = i;
}

int solve(int n){
    int total_divisors = 0;
    for(int i = 0; i < total && p[i] * p[i] <= n; ++i){
        if(n % p[i] == 0){
            int c = 0;
            while(n % p[i] == 0){
                n /= p[i];
                ++c;
                if(c == 2) return 0;
            }
            ++total_divisors;
        }
    }
    if(n > 1) total_divisors++;
    return total_divisors % 2 == 0 ? 1 : -1;
}

int main()
{
    init();
    M[1] = mu[1] = 1;
    for(int i = 2; i <= MX * MX; ++i){
        mu[i] = solve(i);
        M[i] = M[i - 1] + mu[i];
    }
    int n;
    while(scanf("%d", &n) && n){
        printf("%8d%8d%8d\n", n, mu[n], M[n]);
    }
    return 0;
}
