#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 30
using namespace std;
vector<vector<int> > g;
int par[M],res[M];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,cit,que,u,v,cc=0;
    scanf("%d",&t);
    map<string,int> m;
    map<int,string> e;
    string wa,wb;
    while(t--)
    {
        if(cc)printf("\n");
        ++cc;      
        e.clear();
        m.clear();
        g.clear();
        g.resize(M);
        scanf("%d%d",&cit,&que);
        
        int j=1;
        for(int i=0;i<cit;i++)
        {
            cin>>wa>>wb;
            if(!m[wa])m[wa]=j++,e[j-1]=wa;
            if(!m[wb])m[wb]=j++,e[j-1]=wb;
            g[m[wa]].push_back(m[wb]);
            g[m[wb]].push_back(m[wa]);
        }
        
        for(int i=0;i<que;i++)
        {
            cin>>wa>>wb;
            int s=m[wb];
            memset(par,-1,sizeof(par));
            par[m[wa]]=0;
            queue<int> q;
            q.push(m[wa]);
            while(!q.empty())
            {
                u=q.front();
                q.pop();
                int size=g[u].size();
                for(int k=0;k<size;k++)
                {
                     v=g[u][k];   
                     if(par[v]==-1)
                     {
                         par[v]=u;
                         if(v==s)goto end;
                         q.push(v);          
                     }   
                }             
            }
            
            end:    
            if(par[v]!=-1)
            {
                int j=0;          
                res[j++]=s;
                while(par[s]!=-1 && par[s])
                {
                     res[j++]=par[s];            
                     s=par[s];
                }         
                for(int i=j-1;i>=0;i--)
                   printf("%c",e[res[i]][0]);
                printf("\n");
            }                            
        }      
    }
    return 0;
}
