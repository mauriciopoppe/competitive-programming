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
char w[30];
int dp[30][30];
int sum[30][30];
bool b[30][30];
bool solved[30][30];
int get_sum(int i, int j)
{
    if(!b[i][j])
    {
        int s = 0;
        for(int k=i;k<=j;k++)
           s = s + w[k]-'0';
        sum[i][j] = s;
        b[i][j] = 1;
    }
    return sum[i][j];
}

int solve(int i, int j)
{
    printf("start = %d %d\n",i,j);
    if(i == j)
       return 0; 
    
    if(solved[i][j])
       return dp[i][j];
    solved[i][j] = 1;
    int s = 1;
    for(int k = i; k < j; ++k)
    {
        printf("%d %d\n",get_sum(i,k), get_sum(k+1,j));
        SP;    
        if(get_sum(i,k) <= get_sum(k+1,j))
        {
           s += solve(i,k);
           s += solve(k+1,j);
        }
    }
    return dp[i][j] = s;
}

int main()
{
    while(gets(w) && isdigit(w[0]))
    {
         int size = strlen(w);         
         memset(dp,0,sizeof dp);
         memset(b,0,sizeof b);
         memset(solved,0,sizeof solved);
         printf("%d\n",solve(0,size-1)+1);
    }
    return 0;
}
