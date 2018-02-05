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
int a[51];
int c[51];
int gcd(int a, int b)
{
    if(b==0)return a;
    return gcd(b,a%b);    
}

int main()
{
    c[2]=1;
    for(int i=2;i<51;i++)
       c[i+1]=c[i]+i;
    
    
    int n;
    while(scanf("%d",&n) && n)
    {
         int cc=0;
         F(i,n)scanf("%d",&a[i]);
         F(i,n-1)
           FOR(j,i+1,n)
              {
                  int ans;
                  if(a[i]>=a[j])ans=gcd(a[i],a[j]);
                  else ans=gcd(a[j],a[i]);
                  if(ans==1)cc++;         
              }
              
         //printf("%d %d\n",cc,c[n]);
         if(cc)printf("%lf\n",sqrt((6.0*(double)c[n])/(double)cc));
         else printf("No estimate for this data set.\n");
                         
    }
    return 0;
}
