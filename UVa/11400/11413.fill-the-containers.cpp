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
int containers, n;
int v[1002];
int mx;
bool check(int sum)
{
     int c = 0;
     int partial_sum = 0;
     mx = -1;
     for(int i = 0; i < n; ++i)
     {
         if(partial_sum + v[i] <= sum) 
            partial_sum += v[i];
         else
         {
            //if(c == 0 && partial_sum != sum)
            //   return false;
            mx = max(partial_sum, mx), 
            partial_sum = v[i], ++c;
         }
     }
     mx = max(partial_sum, mx);
     ++c;
     return c <= containers;
}

int main()
{
    while(scanf("%d%d", &n, &containers) != EOF)
    {
        int left = IMAX, right = 0;
        for(int i = 0; i < n; ++i) 
            scanf("%d", &v[i]), 
            left = min(left, v[i]),
            right += v[i];
            
        ++right;
        int mid, ans = -1;
        while(left < right)
        {
            mid = (left + right) >> 1;
            if(check(mid))
            {
                ans = mx;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        printf("%d\n", ans);
    }  
    return 0;
}
