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
#define INF 2000000000
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 10005
struct node{
       int to,w,h;
       bool operator<(const node &x)const{
            if(h!=x.h)return x.h<h;
            return x.w<w;
            }
       };

vector<vector<node> > g;
int d[M][2],z;            //d has 2 columns in case that we need a hotel or not
bool isHotel[M];

void printD()
{
     for(int i=1;i<=z;i++)
        printf("%d[%d] ",d[i][0],d[i][1]);
     NL;
}

int main()
{
    int n,hotel,k,h,edg,from,to,val;
    node t,p;
    while(scanf("%d",&n) && n)
    {
         z=n;                
         g.clear();
         g.resize(n+1);
         for(int i=1;i<=n;i++)
            isHotel[i]=0; 
            //d[i][0]=d[i][1]=th[i][0]=th[i][1]=INF;
         
         scanf("%d",&h);
         F(i,h)
              scanf("%d",&k), isHotel[k]=1;

         t.h=0;
         scanf("%d",&edg);
         F(i,edg)
         {
                 scanf("%d%d%d",&from,&to,&t.w);
                 t.to=to;
                 g[from].push_back(t);
                 
                 t.to=from;
                 g[to].push_back(t);                 
         }
         
         priority_queue<node> q;
         t.to=1, t.w=0, t.h=0;
         //d[1][0]=d[1][1]=0, th[1][0]=th[1][1]=0;
         q.push(t);
         //printD();
         //printH();
         //SP;
         bool f=0;
         while(!q.empty())
         {
               p=q.top();
               //printf("%d %d %d\n",p.to,p.w,p.h);
               q.pop();
               if(p.to==n){f=1;break;}
               TR(g[p.to],it)
               {
                    int td=p.w+it->w;
                    if(td<=600)
                    {     
                          //normal route
                          t.to=it->to, t.w=td, t.h=p.h;
                          q.push(t);
                          
                          //take the hotel if there's one
                          if(isHotel[it->to])
                          {
                              t.w=0, t.h=p.h+1;
                              q.push(t);
                          }
                    }
               }
         }
         if(!f)printf("-1\n");
         else printf("%d\n",p.h);
    }
    return 0;
}
