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
#define INF 2147483600
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 505
int d[M],dis[M];
int cd[M];
bool isStation[M];

struct node{
       int to,d;
       bool operator<(const node &x)const
       {
            return x.d<d;
       }
};

vector<vector<node> > g;

void printG(int k)
{
     for(int i=1;i<=k;i++)
     {
         printf("node %d:",i);
         TR(g[i],it)
           printf(" %d[%d]",it->to,it->d);
         NL;            
     }
}

void printD(int k)
{
     for(int i=1;i<=k;i++)
     {
         printf("%d ",d[i]);            
     }
     NL;
}

int main()
{
    //freopen("in2.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,f,k,t,from,to,w;
    char line[500];
    scanf("%d",&n);
    node a,b;
    int cas=0;
    while(n--)
    {
         if(cas)NL;
         ++cas;
              
         scanf("%d%d",&f,&k);
         g.clear();
         g.resize(k+1);

         memset(isStation,0,sizeof(isStation));
         F(i,f)
            scanf("%d",&t), 
            isStation[t]=1;
         getchar();
         
         while(gets(line) && strlen(line))
         {    
              sscanf(line,"%d%d%d",&from,&to,&w);
              a.to=to, a.d=w;
              g[from].push_back(a);
              a.to=from;
              g[to].push_back(a);
         }
         
         //printG(k);
         
         //run dijkstra in all the firestations 
         memset(dis,0,sizeof(dis));
         priority_queue<node> q;  
         F(j,k)
         {
             if(!isStation[j+1])d[j+1]=INF;
             else 
             {
                 d[j+1]=a.d=0;
                 a.to=j+1;
                 q.push(a);
             }
         }

         while(!q.empty())
         {
              a=q.top();
              q.pop();
              dis[a.to]=1;
              TR(g[a.to],it)
              {
                   if(!dis[it->to])
                   {
                         t=d[a.to]+it->d;
                         if(t<d[it->to])
                         {
                             d[it->to]=t;
                             b.to=it->to, b.d=t;
                             q.push(b);           
                         }
                   }
              }
         }
         //printD(k);
         
         //now for every node try to put a firestation and run dijkstra
         int best=1,mx=INF;         
         for(int i=1;i<=k;i++)
         {                 
             if(isStation[i])continue;
             memcpy(cd,d,sizeof(d));
             memset(dis,0,sizeof(dis));
             priority_queue<node> qq;
             cd[i]=0;
             a.to=i, a.d=0;
             qq.push(a);

             while(!qq.empty())
             {
                  a=qq.top();
                  qq.pop();
                  dis[a.to]=1;
                  TR(g[a.to],it)
                  {
                       if(!dis[it->to])
                       {
                             t=cd[a.to]+it->d;
                             if(t<cd[it->to])
                             {
                                 cd[it->to]=t;
                                 b.to=it->to, b.d=t;
                                 qq.push(b);           
                             }
                       }
                  }
                  //printD(k);
             }
             
             int mxx=-INF;
             for(int j=1;j<=k;j++)
                if(!isStation[j] && cd[j]>mxx)
                   mxx=cd[j];
             //printf("%d\n",mxx);
             if(mxx<mx)mx=mxx, best=i;                             
         }
         printf("%d\n",best);
    }
    return 0;
}
