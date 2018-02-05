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
char w[15];
int f(int n)
{
    if((int)log10(n)==0)
       return n;
    int k=0;
    sprintf(w,"%d",n);
    int s=strlen(w);
    F(i,s)k+=w[i]-'0';
    return f(k);    
}

int main()
{
    int n;
    while(scanf("%d",&n) && n)printf("%d\n",f(n));
    return 0;
}
