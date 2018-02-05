#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define INF -999999
using namespace std;

int a[101][101],p[101];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) && n && m)
    {
         for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
             {
                 scanf("%d",&a[i][j]);
                 if(a[i][j])a[i][j]=INF;
                 else a[i][j]=1;    
             }            
         
         int S=INF;
         for(int x=0;x<n;x++)
         {
             memset(p,0,sizeof(p));
             for(int z=x;z<n;z++)
             {
                 int s=INF,t=0;
                 for(int k=0;k<m;k++)
                 {
                     p[k]+=a[z][k];
                     t+=p[k];
                     if(t>s)s=t;
                     if(t<0)t=0;           
                 }            
                 
                 if(s>S)S=s;
             }    
         }
         
         if(S!=INF)printf("%d\n",S);
         else printf("0\n");
    }
    return 0;
}
