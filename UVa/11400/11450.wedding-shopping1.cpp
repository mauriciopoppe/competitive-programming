#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int item[21][21],size[21];
int dp[201][21];
 
int main(){
    int n,m,c,k;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d %d",&m,&c);
        for(int i=0;i<c;i++)
        {
          scanf("%d",&size[i]);                      
          for(int j=0;j<size[i];j++)scanf("%d",&item[i][j]);
        }
        
        int sm=sizeof(dp[0]);
        for(int i=0;i<21;i++)
          fill(dp[i],dp[i]+sm,-1);
        
        //printf("%d %d\n",dp[0][0],dp[1][1]);
        
        for(int i=0;i<=m;i++)
        {
            dp[i][0] = 0;     
            printf("[%d]\n",i);                    
            for(int j=1;j<=c;j++)
            {
                for(int k=0;k<size[j-1];k++)      
                {
                    int it = item[j-1][k];                
                    if (i>=it && dp[i-it][j-1]!=-1)    
                        dp[i][j] >?= dp[i-it][j-1] + it;
                }
            }
            for(int x=0;x<=m;x++)
            {for(int y=0;y<=c;y++)printf("%2d ",dp[x][y]);printf("\n");}
            system("pause");

        }
        if (dp[m][c]==-1) printf("no solution");
        else printf("%d\n",dp[m][c]);
    }
    return 0;
}
