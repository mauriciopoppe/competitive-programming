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
    int dp[100000];
    int v[21];
    int b[100000];
    int s;
    while(scanf("%d",&s))
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
           scanf("%d",&v[i]);
        fill(dp,dp+s+1,0);
        //dp
        for(int i=0;i<n;i++)
        {
            fill(b,b+s+1,0);    
            if(dp[v[i]]==0)
                dp[v[i]]=-1;
            for(int j=0;j<s;j++)
               if((dp[j]!=0 && j!=v[i] && !b[j] && (dp[j+v[i]]==0 || dp[j+v[i]]==-1)) || j==v[i] && v[i]!=-1 && dp[j+v[i]]==0)
               {
                  dp[j+v[i]]=j;
                  b[j+v[i]]=1;
               }
                  
            for(int k=0;k<15;k++)
                    printf("%d ",dp[k]);
            printf("\n");
            
        }
        for(int i=0;i<15;i++)
           printf("%d ",dp[i]);
        printf("\n");
        
        
        
        int i=s;
        while(dp[i]==0){i--;}
        s=i;
        
        vector<int> rev;
        while(dp[i]!=-1)
        {
             rev.push_back(i-dp[i]);                
             i=dp[i];           
        }
        rev.push_back(i);
        
        for(int i=rev.size()-1;i>=0;i--)
            printf("%d ",rev[i]);
        
        printf("sum:%d\n",s);        
    }
    return 0;
}
