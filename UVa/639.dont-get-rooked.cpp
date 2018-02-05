#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n,t=0;
char w[5];
int m[4][4];   

void bt(int c,int sum,int i,int j)
{
     if(c==n*n)
     {
          if(sum>t)t=sum;
          return;    
     }
     else
     {
         if(m[i][j]==-1)
              bt(c+1,sum,(c+1)/n,(c+1)%n);
              
         else
         {
             
                  
             bool f=1;
             for(int k=i-1;k>=0 && m[k][j]!=-1;k--)
                if(m[k][j]==1)f=0;
             
             for(int k=i+1;k<n && m[k][j]!=-1;k++)
                if(m[k][j]==1)f=0;
             
             for(int k=j-1;k>=0  && m[i][k]!=-1;k--)
                if(m[i][k]==1)f=0;
             
             for(int k=j+1;k<n && m[i][k]!=-1;k++)
                if(m[i][k]==1)f=0;           
             
             if(f)
             {    
                             
                  int m2[4][4];
                  for(int k=0;k<n;k++)
                     for(int l=0;l<n;l++)
                        m2[k][l]=m[k][l];
                                                
                  m[i][j]=1;
                  bt(c+1,sum+1,(c+1)/n,(c+1)%n);
                                  
                  for(int k=0;k<n;k++)
                     for(int l=0;l<n;l++)
                        m[k][l]=m2[k][l];
 
                  bt(c+1,sum,(c+1)/n,(c+1)%n);
             }
             else         
                 bt(c+1,sum,(c+1)/n,(c+1)%n);  
         }
     }     
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d",&n) && n)
    {
                      
          for(int i=0;i<n;i++)                         
          {
              memset(m[i],0,sizeof(m[i]));    
              scanf("%s",w);
              for(int j=0;j<n;j++)
                 if(w[j]=='X')m[i][j]=-1;
          }
                
          bt(0,0,0,0);
          printf("%d\n",t);
          t=0;                        
    }
    return 0;
}
