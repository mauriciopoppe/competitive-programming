#include<stdio.h>

int main()
{
    int coins[5]={1,5,10,25,50},i,j;
    long long dp[30002]={0};
    dp[0]=1;
    for(i=0;i<5;i++)
    {
        int c=coins[i];
        for(j=c;j<=30001;j++)
           dp[j]+=dp[j-c];        
    }
    
    int n;
    while(scanf("%d",&n)==1)
    {
         if(dp[n]==1)printf("There is only 1 way to produce %d cents change.\n",n);
         else printf("There are %lld ways to produce %d cents change.\n",dp[n],n);                       
    }
    return 0;
}
