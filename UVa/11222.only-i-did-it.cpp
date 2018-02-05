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
bool m[3][10001];
int c[3];
int main()
{
    int cas,n,t;
    scanf("%d",&cas);
    F(x,cas)
    {
         memset(m,0,sizeof m);
         memset(c,0,sizeof c);
         F(z,3)
         {    
             scanf("%d",&n);
             F(i,n)scanf("%d",&t), m[z][t]=1;       
         }
         F(j,10001)
         {
             int s=0;      
             F(i,3)
               s+=m[i][j];
             if(s>1)
               m[0][j]=m[1][j]=m[2][j]=0;
         }
         
         int mx=-1;
         
         F(i,3)
         {
            F(j,10001)
              if(m[i][j])
                 c[i]++;
            if(c[i]>mx)mx=c[i];
         }
         printf("Case #%d:\n",x+1);
         F(i,3)
         {
             if(c[i]==mx)
             {
                 printf("%d %d",i+1,mx);        
                 F(j,10001)
                     if(m[i][j])
                         printf(" %d",j);
                 NL;
             }
         }
         
    }
    return 0;
}
