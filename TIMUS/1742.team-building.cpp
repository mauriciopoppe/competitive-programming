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
typedef long long LL;
using namespace std;

typedef pair<int, int> pii;
int m[100005];
int con[100005];
int discovered[100005];

bool cmp(const pii &a, const pii &b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

void dfs(int n){
    discovered[n] = 1;
    if(!discovered[con[n]])
        dfs(con[n]);
}

int main(){
    int n, k;
    while(cin >> n){
        memset(m, 0, sizeof m);
        F(i, n){
            cin >> k;
            --k;
            con[i] = k;
            m[k]++;
        }
        vector<pii> v;
        for(int i = 0; i < n; ++i)
            v.push_back(pii(i, m[i]));
        sort(ALL(v), cmp);
        int mn = 0, mx = 0;

        int i = 0;
        for(vector<pii>::iterator it = v.begin(); it != v.end(); ++it)
           m[i++] = it->first;

        memset(discovered, 0, sizeof discovered);
        // find mn
        for(int i = n - 1; i >= 0; --i){
            if(!discovered[m[i]]){
                dfs(m[i]);
                ++mn;
            }
        }

        // find max
        memset(discovered, 0, sizeof discovered);
        for(int i = 0; i < n; ++i){
            if(!discovered[m[i]]){
                dfs(m[i]);
                ++mx;
            }
        }

        printf("%d %d\n", mn, mx);
    }
    return 0;
}
