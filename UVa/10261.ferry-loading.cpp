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
#define M 10001
int w[M],dp[M][M];
bool port[M];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas,t,maxWeight,side;
    scanf("%d",&cas);
    F(z,cas)
    {
         if(z)NL;   
         int n=1;
         scanf("%d",&side);
         side*=100;
         maxWeight=2*side;
         while(scanf("%d",&t) && t)
             w[n++]=t;
         
         //F(i,n)printf("%d ",w[i+1]);NL;    
         //memset(dp,0,sizeof dp);    
         int s=0,mx=1;
         for(;mx<n;++mx)
         {
             if(w[mx]>side || s+w[mx]>maxWeight)break;
             s+=w[mx];
         }
         
         for(int i=1;i<mx;i++)
         {
             memset(dp[i],0,(side+2)*4);
             for(int j=w[i];j<=side;j++)
                  dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);   
         }
         /*printf("%d\n",side);
         for(int i=1;i<=mx;i++)
         {
            for(int j=0;j<=side;j++)
               printf("%d ",dp[i][j]);NL;}*/
         
         memset(port,0,sizeof port);
         for(int i=mx-1,j=side;i>0;i--)
         {
             if(dp[i][j]!=dp[i-1][j])
                  j-=w[i], port[i]=1;
         }
         printf("%d\n",mx-1);
         for(int i=1;i<mx;++i)
           if(!port[i])printf("port\n");
           else printf("starboard\n");
    }
    return 0;
}
