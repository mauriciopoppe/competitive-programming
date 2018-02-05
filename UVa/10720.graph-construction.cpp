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
int v[10005];
int n;

int read()
{
    int total_sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &v[i]);
        if(v[i] < 0) return -1;
        total_sum += v[i];
    }
    if(total_sum % 2 != 0) return -1;
    return total_sum;
}

int solve()
{
    if(read() == -1) return 0;
    int sum_left = 0;
    sort(v + 1, v + n + 1, greater<int>());
    for(int i = 1; i <= n; ++i)
    {
        sum_left += v[i];
        int sum_right = 0;
        for(int j = i + 1; j <= n; ++j)    
            sum_right += min(v[j], i);
        if(sum_left > i * (i - 1) + sum_right)
           return 0;
    }
    return 1;
}

int main()
{
    while(scanf("%d", &n) && n)
    {
        if(solve())
            puts("Possible");
        else
            puts("Not possible");
    }
    return 0;
}
