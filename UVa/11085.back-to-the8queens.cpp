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
int board[100][9],a[9],k;
int q[9];
int candidates(int n, int c[])
{
    int count=0;
    for(int i=0;i<8;i++)
    {
         int j=0;
         for(;j<n;j++)
            if(a[j]==i || abs(a[j]-i)==abs(j-n))break;
         if(j==n)c[count++]=i;
    }
    return count;
}

void bt(int n)
{
     if(n==8)memcpy(board[k++],a,sizeof a);
     else
     {
          int c[9];
          int cand=candidates(n,c);
          F(i,cand)
          {
              a[n]=c[i];
              bt(n+1);
          }
     }
}

int main()
{
    k=0;
    memset(a,0,sizeof a);
    bt(0);
    //printf("%d\n",k);
    //SP;
    int cas=1;
    /*F(i,k)
{       F(j,8)printf("%d ",board[i][j]);NL;}*/
    while(scanf("%d%d%d%d%d%d%d%d",&q[0],&q[1],&q[2],&q[3],&q[4],&q[5],&q[6],&q[7])!=EOF)
    {
         int mn=999999999;
         printf("Case %d: ",cas++);
         F(i,k)
         {
              int s=0;
              F(j,8)
                 if(abs(board[i][j]+1-q[j]))
                  ++s;
              mn=min(s,mn);
         } 
         printf("%d\n",mn);                                                               
    }    
    return 0;
}
