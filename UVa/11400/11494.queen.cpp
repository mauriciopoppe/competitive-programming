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

int main()
{
    int x1, y1, x2, y2;
    while(scanf("%d%d%d%d", &x1, &y1, &x2, &y2))
    {
        if(x1 + x2 + y1 + y2 == 0)
           break;
        if(x1 == x2 && y1 == y2)
        {
            puts("0");
            continue;  
        }            
        if(x1 == x2 || y1 == y2)
        {
            puts("1");
            continue;
        }       
        int a = abs(x1 - x2);
        int b = abs(y1 - y2);
        if(a == b)
           puts("1");
        else
           puts("2");
    }
    return 0;
}
