#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 700
using namespace std;

vector<vector<int> > g;
int val[M],par[M],res[M];
bitset<M> d;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,u,v,len,j;
    string wa,wb;
    map<string,int> m;
    map<int,string> e;
    int cc=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(cc)printf("\n");
        ++cc;                      
        g.clear();
        m.clear();
        g.resize(2*n+1);
        j=1;
        for(int i=0;i<n;i++)
        {
            cin>>wa>>wb;
            if(!m[wa]){m[wa]=j++;e[j-1]=wa;}
            if(!m[wb]){m[wb]=j++;e[j-1]=wb;}
            g[m[wa]].push_back(m[wb]);
            g[m[wb]].push_back(m[wa]);
        }                  
        
        cin>>wa>>wb;
        if(!m[wa] || !m[wb]){printf("No route\n");continue;}
        
        int s=m[wb];
        queue<int> q;
        d.reset();
        memset(val,-1,sizeof(val));
        memset(par,-1,sizeof(par));
        q.push(m[wa]);
        d[q.front()]=1;
        val[q.front()]=0;
        
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
                     d[v]=1;
                     val[v]=val[u]+1;
                     par[v]=u;
                     if(v==s)goto end;
                     q.push(v);     
                 }    
             }                                     
        }
        
        end:
            
        if(val[s]!=-1)
        {
             j=0;         
             res[j++]=s;
             while(par[s]!=-1)
             {
                 res[j++]=par[s];
                 s=par[s];             
             }         
             
             for(int i=j-1;i>=1;i--)
                cout<<e[res[i]]<<" "<<e[res[i-1]]<<endl;
        }
        else printf("No route\n");
            
    }
    return 0;
}
