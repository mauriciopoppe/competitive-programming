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
int a[500];
int main()
{
    int t,n=0;
    while(scanf("%d",&a[n]) && a[n++])
    {
          while(scanf("%d",&a[n]) && a[n++]);
          n--;
          
          double su=0,sd=0,sn=0;
          int cu=0,cd=0;
          int fu=0,fd=0;
          
          for(int i=0;i<n-1;i++)
          {
              if(a[i]<a[i+1])
              {
                  su++;
                  fu=1;
                  if(fd)
                  {
                       if(sn)sd+=sn,sn=0;
                       fd=0;
                       cd++;
                  }           
              }
              else if(a[i]>a[i+1])
              {
                  sd++;
                  fd=1;
                  if(fu)
                  {
                       if(sn)su+=sn,sn=0;
                       fu=0;
                       cu++;
                  }                
              }          
              else sn++;    
          }
          if(fu)su+=sn,cu++;
          else if(fd)sd+=sn,cd++;
          
          if(cu)su/=(double)cu;
          if(cd)sd/=(double)cd;
          
          printf("Nr values = %d:  %lf %lf\n",n,su,sd);
          n=0;
    }
    return 0;
}
