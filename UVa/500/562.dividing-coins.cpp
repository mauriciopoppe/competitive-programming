#include <stdio.h>
#include <stdlib.h>
#define N 101
#define M 25001
#define max(a,b) (a>b?a:b)
int a[N], dp[M];

int main()
{
    int c,n;
    scanf("%d",&c);
    for(int q=0;q<c;q++)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
           {
                scanf("%d",&a[i]);    
                sum+=a[i];
           }
        
        for(int i=0;i<n;i++)
           for(int j=sum/2;j>=a[i];j--)
              if(dp[j]<dp[j-a[i]]+a[i])  
                dp[j]=dp[j-a[i]]+a[i];
              
        printf("%d\n",abs(sum-2*dp[sum/2]));
    }
    return 0;
}
