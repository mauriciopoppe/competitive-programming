#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1025
using namespace std;

long long dp[M],m[M];
int c[6],v[]={1,2,4,10,20,40};
//2 4 2 2 1 0  0.95
int main()
{
    //first compute min number of coins
    fill(dp,dp+M,999999999);
    dp[0]=0;
    for(int i=0;i<6;i++)   
        for(int j=v[i];j<M;j++)
            dp[j]=min(dp[j-v[i]]+1,dp[j]);
    
    //for(int i=0;i<25;i++)printf("%lld ",dp[i]);
    
    int d,cc;    
    while(1)
    {
        scanf("%d%d%d%d%d%d",&c[0],&c[1],&c[2],&c[3],&c[4],&c[5]);
        if(c[0]+c[1]+c[2]+c[3]+c[4]+c[5]==0)break;
        
        int mx=c[0]+c[1]*2+c[2]*4+c[3]*10+c[4]*20+c[5]*40;
        mx=min(mx,1024);
        
        scanf("%d.%d",&d,&cc);
        long long mo=d*100+cc;
        mo/=5;
        
        //compute ways to ammount money
        fill(m,m+M,999999999);
        m[0]=0;
        for(int i=0;i<6;i++)
        {
            for(int k=0;k<c[i];k++)
            {
                 for(int j=mx; j>=v[i] ;j--)
                    m[j]=min(m[j],m[j-v[i]]+1);         
            }                    
        }
        
        long long best=999999999,temp=0;
        for(int i=mo;i<=mx;i++)
            if(m[i])
              best=min(best,m[i]+dp[i-mo]);
        printf("%3d\n",best);               
    }    
    return 0;
}
