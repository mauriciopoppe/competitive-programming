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
    int t,x1,x2,y1,y2,b,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);      
        for(int i=0;i<n;i++)
           fill(a[i],a[i]+n,1);
        
        scanf("%d",&b);
        for(int i=0;i<b;i++)
        {
             scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
             --x1;
             --y1;
             for(int j=x1;j<x2;j++)
                for(int k=y1;k<y2;k++)
                   a[j][k]=INF;                         
        }
        
        int S=INF;
        for(int x=0;x<n;x++)
        {
            memset(p,0,sizeof(p));            
            for(int z=x;z<n;z++)
            {
                 int s=INF,t=0;
                 for(int k=0;k<n;k++)
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
