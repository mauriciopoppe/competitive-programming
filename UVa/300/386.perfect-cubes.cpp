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
int dp[201];
int main()
{
    F(i,201)dp[i]=i*i*i;
    
    for(int i=6;i<201;i++)
    {
       for(int x=2;x<i;x++)
         for(int y=x+1;y<i;y++)
            for(int z=y+1;z<i;z++)
               if(dp[i]==dp[x]+dp[y]+dp[z])               
                 printf("Cube = %d, Triple = (%d,%d,%d)\n",i,x,y,z);
    }
    //system("pause");
    
    return 0;
}
