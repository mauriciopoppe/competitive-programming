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
#define INF 2147400000
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 101

struct node{
       int to, level, w;
       bool operator<(const node& x)const
       {
            return x.w<w;
       }
};

int d[M][5];
bool dis[M][5];
bool level[M][5];

vector<vector<node> > g[5];              //xD
int tme[M];

void printG(int n)
{
     F(i,n)
     {
          printf("level %d\n",i);
          F(j,M)
          {
                if(g[i][j].size())
                {
                     printf("%d: ",j);             
                     TR(g[i][j],it)
                        printf("%d[%d][%d] ",it->to,it->level,it->w);             
                     NL;
                }
          }
          NL;
     }     
}

int main()
{
    int n,k;
    string w;
    node t;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
         F(i,n)scanf("%d",&tme[i]);
         F(i,5)
         {
             g[i].clear();
             g[i].resize(M);
         }
         memset(level,0,sizeof(level));
         memset(dis,0,sizeof(dis)); 
         //t.to=0, t.level=0, t.w=0;        
         //g[0][0].push_back(t);
         //printf("here");
         getchar();
         int ant,now;
         F(i,n)
         {
             getline(cin,w);
             stringstream ss(w);
             string buf;
             ant=-1;
             
             while(ss>>buf)
             {
                 now=atoi(buf.c_str());
                 //printf("%d\n",now);
                 if(ant!=-1)
                 {
                     t.to=ant, t.level=i, t.w=(now-ant)*tme[i];
                     g[i][now].push_back(t);
                     t.to=now;
                     g[i][ant].push_back(t);
                 }
                 ant=now;
                 level[now][i]=1;
                 F(j,n)
                 {
                      if(i!=j && level[now][j])
                      {
                           t.to=now, t.level=i, t.w=60;   
                           g[j][now].push_back(t);
                           t.level=j;
                           g[i][now].push_back(t);
                      }       
                 }
             }
         }
         //printG(n);
         F(i,M)
           F(j,n)
              d[i][j]=INF;
         
         priority_queue<node> q;
         F(i,n)
           if(level[0][i])
           {
               t.to=0, t.level=i, t.w=0;
               d[0][i]=0;
               q.push(t);
           }
         
         while(!q.empty())
         {
               node p=q.top();
               q.pop();
               dis[p.to][p.level]=1;
               if(p.level==k)break;
               TR(g[p.level][p.to],it)
               {
                    if(!dis[it->to][it->level])
                    {
                         int td=d[p.to][p.level]+it->w;
                         if(td<d[it->to][it->level])
                         {
                              d[it->to][it->level]=td;
                              t.to=it->to, t.level=it->level, t.w=td;
                              q.push(t);                      
                         }        
                    }
               }      
         }
         int mn=INF;
         F(i,n)
           if(d[k][i]<mn)mn=d[k][i];
         if(mn==INF)printf("IMPOSSIBLE\n");
         else printf("%d\n",mn);
    }
    return 0;
}
