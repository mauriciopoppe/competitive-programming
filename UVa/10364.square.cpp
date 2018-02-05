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
int dp[4][1 << 20];
int v[20];
int n;
int side;

int calc_length(int side_number, int mask){
    int sm = 0;
    for(int i = 0; i < n; ++i)
       if(mask & (1 << i))
          sm += v[i];
    return sm - side_number * side;
}

int solve(int side_number, int mask){    
    //printf("%d %d\n", side_number, mask);SP;
    if(side_number == 4)
        return 1;

    //calc current length of the mask    
    int current_length = calc_length(side_number, mask);
    if(current_length == side)
        return solve(side_number + 1, mask);
    if(dp[side_number][mask] != -1)
        return dp[side_number][mask];
    else
    {
        int is_solved = 0;
        for(int i = 0; i < n && !is_solved; ++i)
            if((mask & (1 << i)) == 0 &&
                current_length + v[i] <= side)
                    is_solved |= solve(side_number, mask | (1 << i));
        return dp[side_number][mask] = is_solved;
    }    
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        int sum_sides = 0;
        scanf("%d", &n);
        F(i, n)
            scanf("%d", &v[i]),
            sum_sides += v[i];
          
        if(sum_sides % 4 != 0)
            puts("no");        
        else
        {
            side = sum_sides / 4;
            for(int i = 0, mx = 1 << n; i < mx; ++i)
                dp[0][i] = dp[1][i] = dp[2][i] = dp[3][i] = -1;
            if(solve(0, 0))
                puts("yes");
            else
                puts("no");
        }
    }
    return 0;
}
