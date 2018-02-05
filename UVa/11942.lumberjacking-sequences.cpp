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

int main()
{
    int n,a[10];
    scanf("%d",&n);
    printf("Lumberjacks:\n");
    F(i,n)
    {
          F(j,10)
          scanf("%d",&a[j]);
          
          int op=0;
          if(a[0]>a[1])op=1;
          int f=0;
          F(j,9)
          {
               if(op)
                   {if(a[j]<a[j+1]){f=1;break;}}
               else 
                   {if(a[j]>a[j+1]){f=1;break;}}
          }
          if(!f)printf("Ordered\n");
          else printf("Unordered\n");
    }
    return 0;
}
