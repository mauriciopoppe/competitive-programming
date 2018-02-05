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
#define MX 10010

bool prime[MX + 100];
LL p[MX];
LL dp[MX];
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
    
    // solve O(n^2)
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < total; ++i){
        int sm = 0;
        for(int j = i; j >= 0; ++j){
            sm += p[j];
            if(sm > MX)
               break;
            dp[sm]++;
        }
    }
}

int main()
{
    init();
    int n;
    while(scanf("%d", &n) && n){
        printf("%lld\n", dp[n]);
    }
    return 0;
}
