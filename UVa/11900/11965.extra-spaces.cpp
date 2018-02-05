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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,k;
    char c;
    scanf("%d",&n);
    F(q,n)
    {
          if(q)NL;
          scanf("%d",&k);
          printf("Case %d:\n",q+1);
          getchar();
          F(i,k)
          {
              int t=0;  
              while((c=getchar())!='\n')
              {
                   if(c==' ')t=1;
                   else
                   {
                       if(t)putchar(' '),t=0;
                       putchar(c);    
                   }
              }
              if(t)putchar(' '),t=0;
              NL;
          }
    }
    return 0;
}
