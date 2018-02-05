#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define C 21
#define M 201
using namespace std;

int dp[C][M],size[C],r[C][M];

int main()
{
    int t,m,c,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&c);
        for(int i=0;i<c;i++)      
        {
            scanf("%d",&size[i]);
            memset(r[i],-1,(m+2)*4);
            for(int j=0;j<size[i];j++)scanf("%d",&dp[i][j]);            
        }
        memset(r[c],-1,(m+2)*4);
        
        for(int i=0;i<=m;i++)
        {
            r[0][i]=0;
            for(int j=0;j<c;j++)
            {
                 for(int k=0;k<size[j];k++)
                 {
                     int it=dp[j][k];
                     if(i>=it && r[j][i-it]!=-1)
                        r[j+1][i]>?=r[j][i-it]+it; 
                 }    
            }    
            
            /*
            for(int x=0;x<=c;x++)
            {for(int y=0;y<=m;y++)printf("%3d",r[x][y]);printf("\n");}
            system("pause");*/

        }
        
        if(r[c][m]!=-1)printf("%d\n",r[c][m]);
        else printf("no solution\n");
    }
    return 0;
}
