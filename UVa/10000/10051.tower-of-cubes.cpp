#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1000
using namespace std;

int dp[M][7];
int lis[8*M],face[8*M],pred[8*M],cube[8*M],best[M],p[8*M];
int flip[]={1,0,3,2,5,4};
char *names[]={"front","back","left","right","top","bottom"};


int main()
{
    int t,cc=0,i,j,k;
    while(scanf("%d",&t) && t)
    {
        if(cc)printf("\n");
        ++cc;
        for(i=0;i<t;i++)
          for(j=0;j<6;j++)
             scanf("%d",&dp[i][j]);
        
        memset(best,0,sizeof(best));     
        lis[0]=0;
        
        int mx=0,pmax=-1;
        for(k=1,i=0;i<t;i++)
        {
           for(j=0;j<6;j++)
           {
               cube[k+j]=i;                      //cube number
               face[k+j]=j;                      //face
               pred[k+j]=best[dp[i][j]];         //predecesor   
               lis[k+j]=lis[pred[k+j]]+1;        //lis    
           }
           
           //verify lis
           for(j=0;j<6;j++,k++)
              if(lis[k] > lis[best[ dp[i][flip[j]] ]])
                 best[ dp[i][flip[j]]] = k;                            
        }   
        
        mx=0;
        for(i=1;i<k;i++)
           if(lis[i]>mx)mx=lis[i],pmax=i;
        
        i=0;
        while(pmax>0)
            p[i++]=pmax,pmax=pred[pmax];
                
        printf("Case #%d\n",cc);
        printf("%d\n",mx);
        
        for(;i--;)
            printf("%d %s\n",cube[p[i]]+1, names[face[p[i]]]);
    }
    return 0;
}
