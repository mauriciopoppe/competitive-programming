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
#define M 1001
int a[35];
int main()
{
    int t,cas=1;
    while(scanf("%d",&t)!=EOF)
    {          
         int f=0;
         map<int,int> m;
         F(i,t)
         {
               scanf("%d",&a[i]);
               for(int j=i;j>=0;j--)
                  if(m[a[i]+a[j]])f=1;
                  else m[a[i]+a[j]]=1;
         }
         if(a[0]<1)f=1;
         FOR(i,1,t)
               if(a[i-1]>=a[i]){f=1;break;}
         
         printf("Case #%d: ",cas++);
         if(!f)printf("It is a B2-Sequence.\n");
         else printf("It is not a B2-Sequence.\n");
         NL;
    }
    return 0;
}
