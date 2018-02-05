#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 2505
using namespace std;

vector<vector<int> > g;
int val[M],cc[M];
bitset<M> d;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,j,v,u,len,nf,f;
    while(scanf("%d",&n)!=EOF)
    {
        g.clear();
        g.resize(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&nf);
            for(j=0;j<nf;j++)
            {
                scanf("%d",&f);
                g[i].push_back(f);           
            }    
        }                 
        
        scanf("%d",&nf);
        for(int i=0;i<nf;i++)
        {
            scanf("%d",&f);
            queue<int> q;
            memset(val,-1,sizeof(val));
            memset(cc,0,sizeof(cc));
            d.reset();
            d[f]=1;
            val[f]=0;
            cc[val[f]]++;
            q.push(f);
            int mx=1;
            
            while(!q.empty())
            {
                u=q.front();
                q.pop();
                len=g[u].size();
                //printf("%d [%d]\n",u,len);
                for(int i=0;i<len;i++)
                {
                    v=g[u][i];    
                    if(!d[v])
                    {
                         d[v]=1;
                         val[v]=val[u]+1;    
                         mx>?=val[v];
                         cc[val[v]]++;
                         q.push(v);
                    }    
                }            
            }     
            
            int sum=0;
            
            /*
            for(int i=0;i<=mx;i++)
                printf("%d ",cc[i]);
            printf("\n");    
            */
            
            for(int i=0;i<=mx;i++)
                sum+=cc[i];
                
            if(sum==1)printf("0\n");
            else
            {
                int day=-1,mxx=0;
                for(int i=1;i<=mx;i++)
                {
                    if(cc[i]>mxx)
                        day=i,mxx=cc[i];    
                }
                printf("%d %d\n",mxx,day);
            }           
        }
    }
    return 0;
}
