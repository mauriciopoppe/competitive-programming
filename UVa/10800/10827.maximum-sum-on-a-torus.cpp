#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define INF -1000
using namespace std;

int a[100][100],g[100];

int main()
{
    //freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    int t,n;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
               scanf("%d",&a[i][j]);
         
         int S=0,j=-1;
         for(int x=0;x<n;x++)
         {
             memset(g,0,sizeof(g));
             j=x;
             do{              
                 //accumulated
                 for(int k=0;k<n;k++)
                     g[k]+=a[j][k];
                 
                 int t=0,sneg=0,neg=0;                 
                 for(int k=0;k<n;k++)
                 {
                     t+=g[k];
                     //choose max
                     S=max(S,t);
                     if(t<0)t=0;                           
                 }   
                 
                 t=0;
                 for(int k=0;k<n;k++)
                 {
                     t+=g[k];
                     sneg+=g[k];
                     
                     //choose min
                     neg=min(neg,sneg);
                     if(sneg>0)sneg=0;                     
                 }    
                 
                 //choose best
                 if(t-neg>S)S=t-neg; 
                 
                 //move to next row
                 ++j;
                 if(j==n)j=0;
                 
             }while(j!=x);   
         }          
         
         printf("%d\n",S); 
    }
    return 0;
}
