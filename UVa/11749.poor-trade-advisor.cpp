#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 505
#define MV 1000001
using namespace std;

int val[MV][3],t;
vector<vector<int> > g;
bitset<M> d;

void dfs(int u)
{
    d[u]=1;
    ++t;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!d[v])dfs(v);    
    } 
    ++t;
}

int main()
{
    int vert,con,mx,best;
    while(scanf("%d%d",&vert,&con) && vert && con)
    {
         g.clear();                          
         g.resize(vert+1);                          
         d.reset();    
                 
         mx=(1<<31);
         //printf("%d\n",mx);                          
         for(int i=0;i<con;i++)
         {
             scanf("%d%d%d",&val[i][0],&val[i][1],&val[i][2]);    
             mx>?=val[i][2];
         }                  
         
         for(int i=0;i<con;i++)
             if(val[i][2]==mx)
               g[val[i][0]].push_back(val[i][1]),g[val[i][1]].push_back(val[i][0]);    
         
         //print(vert);
         best=0;
         for(int i=1;i<=vert;i++)
         {
             if(g[i].size() && !d[i])
             {   
                 t=0; 
                 dfs(i);
                 t=(t+1)/2;
                 best>?=t;    
             }
         }     
         printf("%d\n",best);   
    }
    return 0;
}
