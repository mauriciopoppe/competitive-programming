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
typedef pair<int, int> pii;

char w[10005];
#define MOD 1000000007
vector<vector<LL> > solve(int start, int end){
    vector<LL> t(10, 0);
    vector<vector<LL> > v;
    F(i, 4) v.PB(t);
    if(start == end){
        v[0][w[start] - '0'] = 1;
        return v;
    }
    int mid = (start + end) >> 1;
    vector<vector<LL> > L = solve(start, mid);
    vector<vector<LL> > R = solve(mid + 1, end);

    for(int j = 0; j < 4; ++j)
        for(int i = 0; i < 10; ++i)
            v[j][i] = (L[j][i] + R[j][i]) % MOD;

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            int s = i + j;
            s = s / 10 + s % 10;

            // 2s
            if(L[0][i] && R[0][j])
                v[1][s] += (L[0][i] * R[0][j]) % MOD;
            // 3s
            if(L[1][i] && R[0][j])
                v[2][s] += (L[1][i] * R[0][j]);
            if(L[0][i] && R[1][j])
                v[2][s] += (L[0][i] * R[1][j]);
            if(v[2][s] >= MOD)
                v[2][s] %= MOD;
            // 4s
            if(L[1][i] && R[1][j])
                v[3][s] += (L[1][i] * R[1][j]);
            if(L[2][i] && R[0][j])
                v[3][s] += (L[2][i] * R[0][j]);
            if(L[0][i] && R[2][j])
                v[3][s] += (L[0][i] * R[2][j]);
            if(v[3][s] >= MOD)
                v[3][s] %= MOD;
        }
    }
//    F(j, 4){ F(i, 10) printf("%d ", L[j][i]);NL;}
//    puts("+");
//    F(j, 4){ F(i, 10) printf("%d ", R[j][i]);NL;}
//    puts("=");
//    F(j, 4){ F(i, 10) printf("%d ", v[j][i]);NL;}
//    puts("***************");
//    NL;
    return v;
}

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        scanf("%s", w);
        vector<vector<LL> > s = solve(0, strlen(w) - 1);
        printf("%lld\n", (s[0][9] + s[1][9] + s[2][9] + s[3][9]) % MOD);
    }
    return 0;
}
