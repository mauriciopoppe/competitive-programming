#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define SP system("pause")
#define M 32
using namespace std;

vector<vector<int> > g;
bitset<M> d;
int val[M];

void print(int t)
{
     for(int i=1;i<=t;i++)
     {
         printf("Node %d,%d:",i,g[i].size());
         for(int j=0;j<g[i].size();j++)
           printf(" %d",g[i][j]);
         printf("\n");    
     }
}

int main()
{
    int n,a,b,j,initial,ttl,cases=1;
    map<int,int> m;
    while(scanf("%d",&n) && n)
    {
         j=1;               
         g.clear();
         g.resize(M);
         m.clear();
         for(int i=0;i<n;i++)
         {
             scanf("%d %d",&a,&b);
             if(!m[a])m[a]=j++;
             if(!m[b])m[b]=j++;
             g[m[a]].push_back(m[b]);
             g[m[b]].push_back(m[a]);
         }         
         
         while(scanf("%d%d",&initial,&ttl))
         {
              if(!initial && !ttl)break;
              
              d.reset();                            
              fill(val,val+M,-1);
              queue<int> q;
              q.push(m[initial]);
              val[q.front()]=0;
              d[q.front()]=1;
                   
              while(!q.empty())
              {
                   int w=q.front();
                   q.pop();
                   for(int i=0;i<g[w].size();i++)
                   {
                       int v=g[w][i];    
                       if(!d[v])
                       {
                           d[v]=1;
                           q.push(v);
                           val[v]=val[w]+1;
                       }
                   }           
              }               
              
              int cc=0;
              for(int i=0;i<M;i++)
                  if(val[i]>=0 && val[i]<=ttl)++cc;   
              
              printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases++,j-1-cc,initial,ttl);      
                
         }       
    }
    return 0;
}
