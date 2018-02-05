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
#define M 1000008
int dp[M];
int s[M];
int main()
{
    memset(dp, 0, sizeof dp);
    for(int i = 1; i < M; ++i){
        for(int j = i; j < M; j += i)
            ++dp[j];
    }
    
    vector<int> v;
    v.push_back(1);
    int i = 1;
    while(1){
        if(v[i - 1] >= M) break;
        int k = v[i - 1] + dp[v[i - 1]];
        v.push_back(k);
        ++i;
    }    
    s[0] = 0;
    i = 0;
    int size = v.size();
    for(int j = 1; j < M; ++j){
        s[j] = s[j - 1];
        if(i < size && v[i] == j)
            ++s[j], ++i;
    }

    int cas;
    int x, y;
    scanf("%d", &cas);
    F(z, cas){
         scanf("%d%d", &x, &y);
         printf("Case %d: %lld\n", z + 1, s[y] - s[x - 1]);
    }
    
    return 0;
}
