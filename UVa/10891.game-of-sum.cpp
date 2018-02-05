#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 102
using namespace std;

int dpa[M][M],dpb[M][M],v[M],sum[M],n,t,s;

int main()
{
    while(scanf("%d",&n) && n)
    {
         sum[0]=0;
         for(int i=0;i<n;i++)scanf("%d",&v[i]),sum[i+1]=sum[i]+v[i];
         
         memset(dpa,0,sizeof(dpa));
         memcpy(dpb,dpa,sizeof(dpa));
         
         for(int i=1;i<=n;i++)
            for(int j=0;j+i<=n;j++)
            {
                dpa[i][j]=v[j]+dpb[i-1][j+1];
                //printf("%d\n",dpa[i][j]);
                
                s=0;
                for(int k=1;k<=i;k++)
                {
                    s+=v[j+k-1];
                    t=s+dpb[i-k][k+j];
                    dpa[i][j]>?=t;
                }
                //printf("%d\n",dpa[i][j]);
                s=0;    
                for(int k=1;k<=i;k++)
                {
                    s+=v[j+i-k];
                    t=s+dpb[i-k][j];
                    dpa[i][j]>?=t;    
                }
                //printf("%d\n",dpa[i][j]);
                dpb[i][j]=sum[i+j]-sum[j]-dpa[i][j];
                
                /*
                for(int x=0;x<=n;x++)
                {for(int y=0;y<=n;y++)printf("%2d ",dpa[x][y]);printf("\n");}printf("\n");
                
                for(int x=0;x<=n;x++)
                {for(int y=0;y<=n;y++)printf("%2d ",dpb[x][y]);printf("\n");}printf("\n");
                
                system("pause");
                */
         }
         printf("%d\n",dpa[n][0]-dpb[n][0]);                          
    }
    return 0;
}
