#include<iostream>
#define R 15
#define C 1121
using namespace std;
int dp[R][C]={0},pred[R][C]={0},p[C]={0};

void print()
{
     for(int i=0;i<4;i++)
     {for(int j=0;j<25;j++)
     printf("%d ",dp[i][j]);
     printf("\n");}
     printf("\n");     
}

int main()
{
    int q=0;
    dp[0][2]=1;
    pred[0][2]=0;
    p[q++]=2;
    int f;
    for(int i=3;i<C;i+=2)
    {
        f=1;        
        for(int j=3;j*j<=i;j+=2)
        if(i%j==0){f=0;break;}
        if(f){dp[0][i]=1;pred[0][i]=q;p[q++]=i;}  
    }    
    int max=q;
    print();
    
    int s;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(dp[i][j]>0)
            {
                 s=dp[i][j]-1;
                 for(int k=pred[i][j]+1;k<max && j+p[k]<C;k++)
                 {
                     if(j+p[k]<C)
                     {    
                     dp[i+1][j+p[k]]=s+dp[i+1][j+p[k]]+1;    
                     pred[i+1][j+p[k]]=k;    
                     }
                     //print();
                     //printf("%d %d %d %d\n",i,j,k,j+p[k]);
                     //system("pause");
                 }                  
            }        
        }                
    }
    
    print();
    system("pause");
    
    int n,k;
    while(1)
    {
        cin>>n>>k;
        if(n+k==0)break;
        printf("%d\n",dp[k-1][n]);
            
    }
    
}
