#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1050
using namespace std;

int val[M+5],pf[M+5][M+5],size[M+5];

void gen()
{
     for(int i=2;i<=M;i++)
     {
         if(!size[i])    
         for(int j=2*i;j<=M;j+=i)
            pf[j][size[j]++]=i;    
     }     
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    gen();
    int a,b,cc=1;
    while(scanf("%d%d",&a,&b) && a && b)
    {
        printf("Case %d: ",cc++);
        if(b<a){printf("-1\n");continue;}
        /*
        for(int i=2;i<=10;i++)
        {
            printf("[%d] ",i);    
            for(int j=0;j<size[i];j++)printf("%d ",pf[i][j]);
            printf("\n");    
        }*/
        
        queue<int> q;
        q.push(a);
        memset(val,0,sizeof(val));
        val[a]=1;
        while(!q.empty())
        {
             int u=q.front();
             //printf("\n%d\n",u);
             q.pop();
             for(int k=0;k<size[u];k++)
             {
                 int v=u+pf[u][k];
                 if(v<=b && !val[v])
                 {
                     val[v]=val[u]+1;
                     //printf("IN %d\n",v);
                     q.push(v);       
                 }    
             }            
        }
        if(val[b])printf("%d\n",val[b]-1);
        else printf("-1\n");
                
    }    
    return 0;
}
