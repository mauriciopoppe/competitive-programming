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
    int h,x;
    while(scanf("%d%d",&h,&x))
    {
         if(h+x==0)break;
         double tmp=log(h)/log(x);
         int i=2;
         for(;;i++)
         {
             double a=log(i/(i+1));    
             if(tmp-a>=0 && tmp-a<=0.5)break;                 
         }
         int g=(int)log(h/(i+1));
         printf("%d\n",g);
    }
    return 0;
}
