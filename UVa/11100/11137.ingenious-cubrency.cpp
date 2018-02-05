#include<iostream>
using namespace std;
long long dp[10001];
int coins[23];
int main()
{
    for(int i=1;i<=21;i++)
       coins[i-1]=i*i*i;
    dp[0]=1;   
    for(int i=0;i<21;i++)
    {
       int c=coins[i];
       for(int j=c;j<=10001;j++)
          dp[j]+=dp[j-c];        
    }
    
    int n;
    while(cin>>n)
         printf("%lld\n",dp[n]);                 
}
