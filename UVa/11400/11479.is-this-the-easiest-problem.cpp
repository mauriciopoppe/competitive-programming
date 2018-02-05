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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int main()
{
    LL t,a[3];
    cin>>t;
    F(q,t)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        printf("Case %d: ",q+1);
        if(a[0]+a[1]<=a[2])printf("Invalid");
        else if(a[0]==a[1] && a[1]==a[2])printf("Equilateral");
        else if(a[0]==a[1] || a[1]==a[2])printf("Isosceles");
        else printf("Scalene");
        NL;  
    }
    return 0;
}
