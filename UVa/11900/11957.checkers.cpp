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
#define MD 1000007
int dp[M][M];
char w[M];
int n;

bool check(int x, int y)
{
     if(x>=0 && x<n && y>=0 && y<n)return 1;
     return 0;
}

int main()
{
    int t;
    int x,y;
    scanf("%d",&t);
    F(q,t)
    {
         memset(dp,0,sizeof(dp));
         scanf("%d",&n);
         for(int i=n-1;i>=0;i--)
         {
             scanf("%s",w);
             F(j,n)
                if(w[j]=='B')dp[i][j]=-1;
                else if(w[j]=='W')dp[i][j]=1;
         }
         int mx=0;
         FOR(i,1,n)
             F(j,n)
                 if(!dp[i][j])
                 {
                     x=i-1,y=j-1;
                     if(check(x,y) && dp[x][y]>0)
                        dp[i][j]+=dp[x][y];
                     
                     y=j+1;
                     if(check(x,y) && dp[x][y]>0)
                        dp[i][j]+=dp[x][y];
                     
                     x=i-2,y=j-2;
                     if(check(x,y) && dp[i-1][j-1]<0 && dp[x][y]>0)
                        dp[i][j]+=dp[x][y];
                     
                     y=j+2;
                     if(check(x,y) && dp[i-1][j+1]<0 && dp[x][y]>0)
                        dp[i][j]+=dp[x][y];                     
                     if(dp[i][j]>MD)dp[i][j]%=MD;
                 }
             F(i,n)if(dp[n-1][i]>0)mx+=dp[n-1][i];
         printf("Case %d: %d\n",q+1,mx%MD);
    }
    return 0;
}
