#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define MAXN 10000
using namespace std;
int mx[MAXN],g[MAXN][MAXN],t[MAXN];

int main()
{
    //freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    int n,T,m,cas;
    scanf("%d",&cas);
    for(int x=0;x<cas;x++)
    {            
        if(x)printf("\n");    
        scanf("%d %d %d",&n,&T,&m);
        memset(mx,0,sizeof(mx));
        
        for(int i=0;i<=m;i++)
           memset(g[i],0,5*T);
           
        for(int i=1;i<=n;i++)
           scanf("%d,",&t[i]);
           
        for(int i=1;i<=n;i++)
        {
           printf("[%d]\n",i);  
           for(int j=m;j>=1;j--)
           {
                g[j][0]=mx[j-1];
                for(int v=T;v>=t[i];v--)
                {
                     if (g[j][v]<=g[j][v-t[i]]+1)
                         g[j][v]=g[j][v-t[i]]+1;
                     if (g[j][v]>mx[j])
                         mx[j]=g[j][v];
                }
                for(int k=0;k<=m;k++)
                {for(int l=0;l<=T;l++)printf("%d ",g[k][l]);printf("\n");}
                printf("\n");
           }
        }
        printf("%d\n",mx[m]);
    }
    return 0;
}
