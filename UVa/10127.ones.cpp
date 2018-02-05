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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
int a[10001];
int main()
{
    int n;
    while(cin>>n)
    {
        int left=0;
        if(a[n])printf("%d\n",a[n]);
        else
        {
           while(1)
           {
               left=(left*10+1)%n;
               ++a[n];
               if(!left)break; 
           }
           printf("%d\n",a[n]);
        }
    }
    return 0;
}
