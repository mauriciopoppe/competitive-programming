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
#define M 50000
char str[M];
int main()
{
    int n;
    str[M - 1] = '\0';
    while(scanf("%d", &n) && n >= 0)
    {
        if(!n)
        {puts("0"); continue;}
        int k = M - 2;
        while(n)
        {
            str[k--] = (char)((n % 3) + '0');
            n /= 3;
        }          
        printf("%s\n", str + k + 1);    
    }
    return 0;
}
