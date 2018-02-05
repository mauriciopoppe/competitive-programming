#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define INF 2147483647

using namespace std;

int a[13][101],next[13][101];

int r,c;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d%d",&r,&c)!=EOF)
    {                                                      
         for(int i=1;i<=r;i++) 
            for(int j=1;j<=c;j++) 
               scanf("%d",&a[i][j]),next[i][j]=-1;
         
         
         int pos[3];
         for(int j=c-1;j>=1;j--)
         {   
             
             for(int i=1;i<=r;i++)
             {                      
                  int mn=INF;
                  pos[0]=i-1;
                  if(!pos[0])pos[0]=r;
                  pos[1]=i;
                  pos[2]=i+1;
                  if(pos[2]==r+1)pos[2]=1;
                            
                  for(int k=0;k<3;k++)
                  {                                                   
                      if(a[pos[k]][j+1]<mn)
                      {
                         mn=a[pos[k]][j+1];
                         next[i][j]=pos[k];                                     
                      }
                      else if(a[pos[k]][j+1]==mn)
                         next[i][j]=min(next[i][j],pos[k]);
                  }
                  
                  a[i][j]+=mn;
             }                                                    
         }  
         
         
         //find min         
         int mn=INF,ptr=-1;
         for(int i=1;i<=r;i++)
            if(a[i][1]<mn)mn=a[i][1],ptr=i;
         
         printf("%d",ptr);
         
         //do some backtracking       
         for(int i=1;i<c;i++)
         {
              printf(" %d",next[ptr][i]);
              ptr=next[ptr][i];                   
         }
         
         printf("\n%d\n",mn);        
    }
    return 0;
}
