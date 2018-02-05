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
    //printf("%d\n",0xff);
    int t,to,con,n,color,u,from;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&con);
        memset(g,0,sizeof(g));
        memset(scc,0,sizeof(scc));
        
        for(int i=0;i<con;i++)
        {
            scanf("%d%d",&from,&to);
            if(from>=0 && to>=0 && from<n && to<n)g[from][to]=g[to][from]=1;                   
        }
        
        int mx=0;
        //printf("%d\n",n);
        for(int i=0;i<n;i++)
        {
            if(!scc[i])    
            {
                int temp=M,num,cool=0;
                for(int k=1;k<=2;k++)
                {
                    memset(val,0,sizeof(val));
                                    
                    num=0;
                    cool=1;

                    queue<int> q;
                    q.push(i);
                    val[i]=k;
                    scc[i]=1;
                    if(val[i]==1)num++;
                    
                    while(!q.empty())
                    {
                         u=q.front();
                         q.pop();
                         for(int j=0;j<n;j++)
                         {
                              if(g[u][j])
                              {
                                  if(!val[j])
                                  {       
                                      val[j]=3-val[u]; 
                                      scc[j]=1;                             
                                      if(val[j]==1)num++;
                                      q.push(j);
                                  }
                                  else if(val[j]==val[u])cool=-1;
                              }                                      
                         }
                    }
                    //printf(" %d\n",cool);
                    if(cool==-1)
                        temp=-1;        
                    else 
                    {     
                        int qq=cool*num;
                        if(qq>0) temp<?=(cool*num);
                    }
                    //printf("%d\n",temp);
                }
                if(temp==-1){mx=-1;break;}
                mx+=temp;
            }
        }
        if(mx>0)printf("%d\n",mx);
        else printf("-1\n");
    }
    return 0;
}
