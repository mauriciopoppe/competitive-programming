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
#define M 200000
int x[M], y[M];
int k = 0;
void gen(int n)
{
     //one down     
     x[k] = x[k - 1];
     y[k] = y[k - 1] + 1;
     ++k;
     
     //n - 1 to the SW
     for(int i = 0; i < n - 1; ++i)
     {
        x[k] = x[k - 1] - 1;
        y[k] = y[k - 1] + 1;
        ++k;
     }
     
     //n to the NW
     for(int i = 0; i < n; ++i)
     {
        x[k] = x[k - 1] - 1;
        y[k] = y[k - 1];
        ++k;
     }
     
     //n to the N
     for(int i = 0; i < n; ++i)
     {
        x[k] = x[k - 1];     
        y[k] = y[k - 1] - 1;
        ++k;
     }
     
     //n to the NE
     for(int i = 0; i < n; ++i)
     {
        x[k] = x[k - 1] + 1;     
        y[k] = y[k - 1] - 1;
        ++k;
     }
     
     //n to the SE
     for(int i = 0; i < n; ++i)
     {
        x[k] = x[k - 1] + 1;     
        y[k] = y[k - 1];
        ++k;
     }
     
     //n to the S
     for(int i = 0; i < n; ++i)
     {
        x[k] = x[k - 1];     
        y[k] = y[k - 1] + 1;
        ++k;
     }
}


int main()
{
    x[0] = y[k++] = 0;
    for(int i = 1; k <= 100000; ++i)
       gen(i);
    
    int n;
    while(scanf("%d", &n) != EOF)
        printf("%d %d\n",x[n - 1], y[n - 1]);
    return 0;
}
