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
int n;
int solve(int start)
{
    for(int i = start; i >= 1; --i)
    {
        int people = i;
        int coconuts = n;
        int j = 0;
        for(j = 0; j < people; ++j)
        {
            if(coconuts % people != 1)
                break;
            --coconuts;
            coconuts -= coconuts / people;    
        }
        if(j == people && coconuts % people == 0)
            return i;        
    }
    return -1;
}

int main()
{
    while(scanf("%d", &n) && n >= 0)
    {
        int start = (int)sqrt(n) + 1;
        int k = solve(start);
        if(k != -1)
            printf("%d coconuts, %d people and 1 monkey\n", n, k);
        else
            printf("%d coconuts, no solution\n", n); 
    }
    return 0;
}
