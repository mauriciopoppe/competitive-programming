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
#define M 12005
bitset<M + 5> bt;
int prime[M], n;
int n_primes[M];
void seive()
{
     for(int i = 4; i < M; i += 2)
        bt[i] = 1;
     for(int i = 3; i * i <= M; i += 2)
        if(!bt[i])
           for(int j = i * i; j <= M; j += 2 * i)
              bt[j] = 1;
     prime[0] = 2;
     n = 1;
     for(int i = 3; i <= M; i += 2)
        if(!bt[i])
           prime[n++] = i;
}

bool is_prime(int k)
{
     for(int i = 0; prime[i] * prime[i] <= k; ++i)
        if(k % prime[i] == 0)     
           return false;
     return true;
}

int main()
{
    int a, b;
    seive();
    n_primes[0] = 1;
    for(int i = 1; i <= 10000; ++i)
       n_primes[i] = n_primes[i - 1] + is_prime(i * i + i + 41);
    
    while(scanf("%d%d", &a, &b) != EOF)
         printf("%.2lf\n", (double)(n_primes[b] - n_primes[a - 1]) / (double)(b - a + 1) * 100.0 + 1e-9);
    return 0;
}
