#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 210
using namespace std;

vector<vector<int> > g;
bitset<M> col,d;
bitset<2> test;

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
    int n,con,u,v,len,from,to;
    bool color;
    while(scanf("%d",&n) && n)
    {
         scanf("%d",&con);
         g.clear();                
         g.resize(n);
         for(int i=0;i<con;i++)
            scanf("%d%d",&from,&to),g[from].push_back(to),g[to].push_back(from);
         
         d.reset();
         col.reset();
         
         color=0;
         queue<int> q;
         q.push(0);
         d[0]=1;
         
         while(!q.empty())
         {
              u=q.front();
              q.pop();
              color=!col[u];
              
              len=g[u].size();
              //printf("%d\n",len);
              for(int k=0;k<len;k++)
              {
                  v=g[u][k];    
                  if(!d[v])    
                  {
                      col[v]=color;
                      d[v]=1;
                      q.push(v);
                  }
              }            
         }                 
         
         bool f=0;
         for(int i=0;i<n;i++)
         {
            test.reset();    
            len=g[i].size();     
            for(int k=0;k<len;k++)
               test[col[g[i][k]]]=1;
            
            if(test[0] && test[1]){f=1;break;}
         }
         
         if(f)printf("NOT BICOLORABLE.\n");
         else printf("BICOLORABLE.\n");
    }
    return 0;
}
