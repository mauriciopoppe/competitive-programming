#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 101
using namespace std;

vector<vector<int> > g;
int mx,best,temp;
bitset<M> d;

void dfs(int u)
{ 
    d[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!d[v])dfs(v);    
    } 
}

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
    int t,con,node;
    while(scanf("%d",&t) && t)
    {
        g.clear();                
        g.resize(t+1);
        for(int i=1;i<=t;i++)
        {          
            scanf("%d",&con);
            for(int j=0;j<con;j++)
            {
                  scanf("%d",&node);
                  g[i].push_back(node);  
            }    
        }
        
        //print(t);
        mx=0,best=-1;
        for(int i=1;i<=t;i++)
        {   
                d.reset();     
                dfs(i);
                temp=d.count();
                //printf("%d [%d]\n",i,temp);
                if(temp>mx){mx=temp;best=i;}
        }                 
        printf("%d\n",best);
    }
    return 0;
}
