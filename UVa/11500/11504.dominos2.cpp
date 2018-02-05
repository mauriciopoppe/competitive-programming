#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 10005
using namespace std;

vector<vector<int> > g;
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

int main()
{
    int q,n,m,l,x,y;
    scanf("%d",&q);
    while(q--)
    {
        d.reset();
        g.clear();
             
        scanf("%d%d%d",&n,&m,&l);
        g.resize(n+1);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            g[x].push_back(y);   
        }
        
        for(int i=0;i<l;i++)
        {
            scanf("%d",&x);
            if(!d[x])dfs(x);   
        }
        printf("%d\n",d.count());
    }
    return 0;
}
