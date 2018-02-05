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

bool g[M][M];
int val[M],scc[M];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t,to,con,n,color,u;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(g,0,sizeof(g));
        memset(scc,-1,sizeof(scc));
        
        //printf("%d %d\n",scc[0],scc[1]);
        
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&con);
            for(int j=0;j<con;j++)
            {   
                scanf("%d",&to);
                if(to>0 && to<=n)g[i][to]=g[to][i]=1;
            }                   
        }
        
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            if(!scc[i])    
            {   
                int temp=0,num,cool=0;
                for(int k=1;k<=2;k++)
                {                   
                    memset(val,0,sizeof(val));
                                    
                    num=0;
                    cool=1;
                                 
                    queue<int> q;
                    q.push(i);
                    val[i]=k;
                    scc[i]=i;
                    if(val[i]==1)num++;
                    
                    while(!q.empty())
                    {
                         u=q.front();
                         q.pop();
                         for(int j=1;j<=n;j++)
                         {
                              if(g[u][j])
                              {
                                  if(!val[j])
                                  {       
                                      val[j]=3-val[u]; 
                                      scc[j]=i;                             
                                      if(val[j]==1)num++;
                                      q.push(j);
                                  }
                                  else if(val[j]==val[u])cool=0;
                              }                                      
                         }
                    }
                    //printf(" %d\n",cool);
                    temp>?=(cool*num);
                    //printf("%d\n",temp);
                }             
                
                mx+=temp;
            }
        }        
        printf("%d\n",mx);
    }
    return 0;
}
