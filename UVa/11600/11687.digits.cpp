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
char w[2000000], x[2000000];
int cnt, len;
int solve(int n)
{
    sprintf(x, "%d", n);
    len = strlen(x);
    ++cnt;
    if(len == n) return cnt;
    return solve(len);
}

int main()
{
    while(gets(w) && w[0] != 'E')
    {
       if(!strcmp(w, "1"))
       {
           puts("1");
           continue;          
       }
       cnt = 1;    
       printf("%d\n", solve(strlen(w)));
    }
    return 0;
}
