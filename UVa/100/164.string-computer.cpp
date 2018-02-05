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
#define M 22
int dp[M][M],par[M][M],sn,sm;
char m[M],n[M];
int path[M],ind;
void print()
{
     F(i,sm+1)
     {F(j,sn+1)printf("%d ",dp[i][j]);NL;}       
}

void printPar()
{
     F(i,sm+1)
     {F(j,sn+1)printf("%d ",par[i][j]);NL;}       
}

enum{KEEP=0,CHANGE,INSERT,DELETE};

void printPath(int x, int y)
{
     if(x==0 && y==0)return;
     if(par[x][y]==KEEP)printPath(x-1,y-1), path[ind++]=KEEP;
     else if(par[x][y]==CHANGE)printPath(x-1,y-1), path[ind++]=CHANGE;
     else if(par[x][y]==INSERT)printPath(x-1,y), path[ind++]=DELETE;
     else printPath(x,y-1), path[ind++]=INSERT;
}

void editDistance()
{
     memset(par,0,sizeof par);
     memset(path,0,sizeof path);
     for(int i=1;i<M;i++)
       dp[i][0]=dp[0][i]=i,
       par[i][0]=INSERT, par[0][i]=DELETE;
     
     
     for(int i=1;i<=sm;i++)
     {
         for(int j=1;j<=sn;j++)
         {
              if(m[i-1]==n[j-1])dp[i][j]=dp[i-1][j-1], par[i][j]=KEEP;
              else
              {
                  int mn=dp[i-1][j-1];
                  par[i][j]=CHANGE;
                  if(dp[i-1][j]<mn) mn=dp[i-1][j], par[i][j]=INSERT;
                  if(dp[i][j-1]<mn) mn=dp[i][j-1], par[i][j]=DELETE;
                  dp[i][j]=mn+1;
              }
         }
         print();
         NL;
         printPar();
         SP;
     }
     ind=0;
     printPath(sm,sn);
     printf("%d\n",dp[sm][sn]);
     for(int i=0;i<ind;i++)
        if(path[i]==KEEP)printf("Keep\n");
        else if(path[i]==CHANGE)printf("Change\n");
        else if(path[i]==INSERT)printf("Insert\n");
        else printf("Delete\n");

}

int main()
{
    while(scanf("%s",m) && strcmp(m,"#"))
    {
         scanf("%s",n);
         sn=strlen(n);
         sm=strlen(m);                
         editDistance();
    }
    return 0;
}
