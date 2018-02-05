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
#define M 101
int pos[M][M];
int points[M];
int x[M];
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    int row,col,q,n;
    while(scanf("%d%d",&row,&col))
    {
         if(row+col==0)break;
         F(i,row)
           F(j,col)
             scanf("%d",&pos[i][j]);                         
         scanf("%d",&q);
         F(z,q)
         {
             memset(points,0,sizeof points);
             memset(x,0,sizeof x);  
             scanf("%d",&n);
             F(i,n)scanf("%d",&points[i]);
             F(i,row)
               F(j,col)
                 x[j]+=points[pos[i][j]-1];
             int mx=-1;
             F(j,col)mx=max(mx,x[j]);
             int c=0;
             F(i,col)
               if(x[i]==mx)
               {
                   if(c)printf(" ");
                   c=1;
                   printf("%d",i+1);        
               }             
             NL;
         }    
    }
    return 0;    
}
