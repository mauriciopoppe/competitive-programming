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
LL get(LL a)
{
    LL c=0;
    while(1)
    {
        if(a%2!=0) a=LL(a*3)+1;
        else a/=2;
        //printf("%d\n",a);
        ++c;
        if(a==1)break;
    }        
    return c;
}
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    LL a,b;
    while(cin>>a>>b && a && b)
    {
         if(b<a)swap(a,b);           
         LL mx=0,p=1;           
         for(LL i=a;i<=b;i++)
         {
              LL t=get(i);
              if(t>mx)mx=t,p=i;
              //printf("%d\n",mx);
         }
         printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",a,b,p,mx);
    }
    return 0;
}
