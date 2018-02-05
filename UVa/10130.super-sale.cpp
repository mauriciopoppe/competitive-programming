#include<iostream>
#include<algorithm>
#define M 1010
using namespace std;

int main()
{
    int dp[M],t,n,g;
    int v[M],w[M],G[M];
    
    cin>>t;
    for(int q=0;q<t;q++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>v[i]>>w[i];       
        memset(dp,0,sizeof(dp));
        for ( int j = 0; j < n; j++ ) 
                for ( int i = 32; i >= 0; i-- ) 
                   if ( w [j] <= i && dp [i] < dp [i - w[j]] + v[j] )
                       dp [i] = dp [i - w[j]] + v[j]; 
        cin>>g;
        int sum=0,num;
        for(int i=0;i<g;i++)
           {
                cin>>num;
                sum+=dp[num];
           }        
        printf("%d\n",sum);
    }  
}
