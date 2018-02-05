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
    int b1, b2;
    int start, end, cas;
    scanf("%d", &cas);
    int w1[500];
    int to_base[500];
    while(cas--)
    {
        scanf("%d%d%d%d", &b1, &b2, &start, &end);
        int i;
        for(i = end; i >= start; --i)
        {
            int size = 0;
            int k = i;
            while(k)
            {
                w1[size++] = k % b1;
                k /= b1;    
            }
            int total = 0;
            int cb2 = 1;
            for(int j = 0; j < size; ++j)
               total += w1[j] * cb2,
               cb2 *= b2;
            if(total % i == 0) break;               
        }
        if(i < start) puts("Non-existent.");
        else printf("%d\n", i);
    }
    return 0;
}
