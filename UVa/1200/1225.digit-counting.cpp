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
#define M 10001
int v[M][10];
int main()
{
    char w[500];
    memset(v[0], 0, sizeof v[0]);
    for(int i = 1; i <= 10000; ++i)
    {
       sprintf(w, "%d", i);
       for(int j = 0; j < 10; ++j)
          v[i][j] = v[i - 1][j];
          
       for(int j = 0; w[j]; ++j)
          ++v[i][w[j] - '0'];
    }
    int n;
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        for(int i = 0; i < 10; ++i)
        {
           if(i) putchar(' ');
           printf("%d", v[n][i]);
        }
        NL;
    }
    return 0;
}
