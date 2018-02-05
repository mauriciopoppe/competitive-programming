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
char res[500];
int check_digits[10];
char num[20], den[20];

int test_digits(char *w)
{
    memset(check_digits, 0, 40);
    for(int i = 0; w[i]; ++i)
    {
       if(check_digits[w[i] - '0'])
          return 0;
       check_digits[w[i] - '0'] = 1;
    }
    return 1;
}

void solve()
{
    if(strlen(res) > 10)
       return;
    LL n;
    sscanf(res, "%lld", &n);
    //printf("%d\n", (int) log10(n));
    for(LL i = 1; (int)log10(i * n) < 10; ++i)
    {
        sprintf(num, "%lld", i * n);
        sprintf(den, "%lld", i);
        if(test_digits(num) && test_digits(den))
           printf("%s / %s = %lld\n", num, den, n);
    }
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%s", res);
        solve();
        if(cas)NL;
    }
    return 0;
}
