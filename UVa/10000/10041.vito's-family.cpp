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
#define NL printf("\n")
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
int a[550];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,n,x;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         F(i,n)scanf("%d",&a[i]);
         sort(a,a+n);
         int m=n>>1;
         int sum=2147483647,mn=0;
         //cout<<sum<<endl;
         F(i,n)mn+=abs(a[i]-a[m]);
         if(mn<sum)sum=mn;
         
         if(!(n&1))
         {
              mn=0;++m;
              F(i,n)mn+=abs(a[i]-a[m]);
              if(mn<sum)sum=mn;
         }
         printf("%d\n",sum);
    }
    return 0;
}
