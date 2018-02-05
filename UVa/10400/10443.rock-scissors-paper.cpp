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
int z[101][2];
int main()
{
    int p,k,cas=0,x,y;
    string a,b;
    while(scanf("%d",&p) && p)
    {
         if(cas)NL;
         cas=1;               
         scanf("%d",&k);
         k=k*p*(p-1)/2;
         memset(z,0,sizeof z);
         F(i,k)
         {
              cin>>x>>a>>y>>b;
              if(a==b)continue;
              if((a=="scissors" && b=="paper") || (a=="rock" && b=="scissors") || (a=="paper" && b=="rock"))
                  z[x][0]++, z[y][1]++;
              else
                  z[x][1]++, z[y][0]++;
         }
         for(int i=1;i<=p;i++)
         {
              int t=z[i][0]+z[i][1];   
              if(t==0)printf("-\n");
              else printf("%.3lf\n",double(z[i][0])/double(t));   
         }
    }
    return 0;
}
