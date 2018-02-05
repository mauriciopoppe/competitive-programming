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
#define M 501
bool m[M][M];
int main()
{
    int w,h,n;
    while(1)
    {
         scanf("%d%d%d",&w,&h,&n);
         if(w+h+n==0)break;
         memset(m,0,sizeof(m));
         int x1,y1,x2,y2;
         F(i,n)
         {
             scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
             if(y1>y2)swap(y1,y2);
             if(x1>x2)swap(x1,x2);
             //printf("  %d %d %d %d\n",x1,y1,x2,y2);
             FOR(j,x1,x2+1)
               FOR(k,y1,y2+1)
                  m[j][k]=1;
         }
         
         int c=0;
         FOR(i,1,w+1)
           FOR(j,1,h+1)
             if(!m[i][j])++c;
         if(!c)printf("There is no empty spots.\n");
         else if(c==1)printf("There is one empty spot.\n");
         else printf("There are %d empty spots.\n",c);
    }
    return 0;
}
