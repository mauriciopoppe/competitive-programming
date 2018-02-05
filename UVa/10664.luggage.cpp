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
#define M 201
int dp[M];
int w[M];
char s[M*2+1];
int main()
{
    int cas;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
         gets(s);
         char *ptr=strtok(s," ");
         int k=0,sum=0;
         while(ptr!=NULL)
         {
              sum+=w[k++]=atoi(ptr);
              ptr=strtok(NULL," ");
         }
         
         if(sum%2){printf("NO\n");continue;}
         
         //knapsack
         memset(dp,0,sizeof dp);
         dp[0]=0;
         for(int i=0;i<k;++i)
            for(int j=sum;j>=w[i];--j)
               dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
         
         if(dp[sum]==sum && dp[sum/2]==sum/2)
            printf("YES\n");
         else printf("NO\n");
    }   
    return 0;
}
