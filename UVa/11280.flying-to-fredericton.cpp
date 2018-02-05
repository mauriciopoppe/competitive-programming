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
#define C 110
#define INF 1000000000
typedef long long LL;
int weight[C][C];
int d[C][C],cities,edg;
int q[C],mx;

void printD()
{
     F(i,cities+1)
     {
         printf("city %d\n",i);
         F(j,mx+1)
              printf("%d ",d[i][j]);  
         NL;     
     } 
}
int main()
{
    //freopen("ftf.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas,val;
    string x,y;
    scanf("%d",&cas);
    F(z,cas)
    {
         if(z)NL;   
         map<string,int> m;
         scanf("%d",&cities);
         F(i,cities)
            cin>>x, m[x]=i;
            
         F(i,cities)
              fill(weight[i],weight[i]+cities,INF);
 
         scanf("%d",&edg);
         F(i,edg)
         {
              cin>>x>>y>>val;
              int s=m[x], e=m[y];
              weight[s][e]=min(weight[s][e], val);
         }

         int source=0;
         int dest=cities-1;
         
         int que;
         mx=0;
         scanf("%d",&que);
         F(i,que)
         {
            scanf("%d",&q[i]);
            if(q[i]<0)q[i]=0;
            if(q[i]>cities)q[i]=cities;
            mx=max(mx,q[i]);
         }
         mx++;
         F(i,cities)
            fill(d[i],d[i]+mx+1,INF);
         d[source][0]=0;
         
         //dp
         for(int i=0;i<cities;i++)
         {
            for(int x=i+1;x<cities;x++)
            {
                  for(int y=1;y<=mx;y++)
                        d[x][y]=min(min(d[x][y-1],d[x][y]),d[i][y-1]+weight[i][x]);
            }
         }
         
         printf("Scenario #%d\n",z+1);
         F(i,que)
               if(d[dest][q[i]+1]!=INF)
                    printf("Total cost of flight(s) is $%d\n",d[dest][q[i]+1]);
               else printf("No satisfactory flights\n");
    }
    return 0;
}
