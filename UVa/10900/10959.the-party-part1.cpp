#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1005
using namespace std;

vector<vector<int> > g;
int d[M];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,n,con,from,to,u,v,len; 
    scanf("%d",&t);
    for(int z=0;z<t;z++)
    {
         if(z)printf("\n");   
         scanf("%d%d",&n,&con);
         g.clear();
         g.resize(n+1);
         for(int i=0;i<con;i++)
         {
             scanf("%d%d",&from,&to);
             if(find(g[from].begin(),g[from].end(),to)==g[from].end())    
                g[from].push_back(to);
             if(find(g[to].begin(),g[to].end(),from)==g[to].end())    
                g[to].push_back(from);
         }
         
         memset(d,0,sizeof(d));
         queue<int> q;
         q.push(0);
         d[0]=1;
         
         while(!q.empty())
         {
             u=q.front();
             q.pop();
             len=g[u].size();
             for(int i=0;i<len;i++)
             {
                  v=g[u][i];
                  if(!d[v])
                  {
                      q.push(v);
                      d[v]=d[u]+1;  
                  }   
             }                       
         }
         for(int i=1;i<n;i++)
           printf("%d\n",d[i]-1);
    }
    return 0;
}
