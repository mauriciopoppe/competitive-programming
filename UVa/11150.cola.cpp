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

int main()
{
    int n;
    int dp[201]={0};
    while(cin>>n)
    {
         //if i did something already
         if(dp[n])printf("%d\n",dp[n]);
         else
         {
             //no bottles borrowed
             int sum=0,b=n,l=0;
             while(b>0)
             {
                 sum+=b;
                 l+=b;
                 b=l/3;
                 l%=3;
             }
             dp[n]=max(dp[n],sum);
             
             //1 bottle borrowed
             sum=0;b=n;l=1;
             while(b>0)
             {
                 sum+=b;
                 l+=b;
                 b=l/3;
                 l%=3;
             }
             if(l>0)dp[n]=max(dp[n],sum);
             
             //2 bottles borrowed
             sum=0;b=n;l=2;
             while(b>0)
             {
                 sum+=b;
                 l+=b;
                 b=l/3;
                 l%=3;
             }
             if(l>1)dp[n]=max(dp[n],sum);
             printf("%d\n",dp[n]);
         }
    }
    return 0;
}
