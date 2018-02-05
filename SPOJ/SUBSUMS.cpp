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
int a[2][17];
int LEFT, RIGHT;
int mx, pos;
vector<int> v[2];

void solve(int k, int sum){
    if(k == mx)
        v[pos].push_back(sum);
    else{
        solve(k + 1, sum);
        solve(k + 1, sum + a[pos][k]);
    }
}

int main(){
    int n;
    while(scanf("%d%d%d", &n, &LEFT, &RIGHT) != EOF){
        v[0].clear(); v[1].clear();
        for(int i = 0; i < n / 2; ++i)
            scanf("%d", &a[0][i]);
        for(int i = n / 2, j = 0; i < n; ++i, ++j)
            scanf("%d", &a[1][j]);

        pos = 0;
        mx = n / 2;
        solve(0, 0);

        pos = 1;
        mx = n - n / 2;
        solve(0, 0);
        sort(v[1].begin(), v[1].end());

        LL total = 0;
        int size = v[0].size(), x, start, end, mid, pos_left, pos_right;
        int size_bs = v[1].size();
        for(int i = 0; i < size; ++i){
            x = RIGHT - v[0][i];
            pos_left = 1000000000;
            pos_right = -1000000000;

//            printf("x = %d\n", x);
            start = 0, end = size_bs - 1, mid = -1;
            while(start <= end){
                mid = start + (end - start) / 2;
                if(x >= v[1][mid]) start = mid + 1, pos_right = mid;
                else end = mid - 1;
            }

            x = LEFT - v[0][i];
//            printf("x = %d\n", x);
            start = 0, end = size_bs - 1, mid = -1;
            while(start <= end){
                mid = start + (end - start) / 2;
                if(x <= v[1][mid]) end = mid - 1, pos_left = mid;
                else start = mid + 1;
            }

//            printf("%d %d\n", pos_left, pos_right);
            if(pos_left < size_bs && pos_right >= 0)
                total += LL(pos_right - pos_left + 1);
        }
        printf("%lld\n", total);
    }
    return 0;
}
