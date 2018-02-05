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
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

double a[1001];

int main()
{
    double res,t;
    int n,k;
    cin>>n;
    while(n--)
    {
        res=0;
        cin>>k;
        F(i,k)cin>>a[i],res+=a[i];
        res/=k;
        int c=0;
        F(i,k)c+=a[i]>res?1:0;
        printf("%.3lf%\n",((double)c*100.0)/(double)k);     
    }
    return 0;
}
