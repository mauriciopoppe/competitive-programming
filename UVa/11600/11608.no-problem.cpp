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

int a[13],b[13];

int main()
{
    int n,cas=1;
    while(scanf("%d",&a[0]) && a[0]>=0)
    {                            
          FOR(i,1,13)scanf("%d",&a[i]); 
          F(i,12)scanf("%d",&b[i]);
          printf("Case %d:\n",cas++);          
          int t=0;
          F(i,12)
          {
                if(a[i]+t>=b[i])
                {
                      t+=a[i]-b[i];
                      printf("No problem! :D\n");
                }
                else t+=a[i], printf("No problem. :(\n");
          }
          
    }
    return 0;
}
