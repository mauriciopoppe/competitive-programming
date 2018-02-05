#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<utility>
#include<bitset>
#include<climits>
#include<cfloat>
#include<list>
#define M 26
using namespace std;

int g[M][M],d[M][M],n;
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};

bool check(int i, int j)
{
     if(i>=0 && i<n && j>=0 && j<n)return true;
     return false;
}

void dfs(int i,int j)
{
     d[i][j]=1;
     for(int k=0;k<8;k++)
     {
         int a=i+dx[k],b=j+dy[k];    
         if(check(a,b) && !d[a][b] && g[a][b])dfs(a,b);    
     }     
}

int main()
{
    char w[M+1];
    int cc=1;
    while(scanf("%d",&n)!=EOF)
    {
    memset(d,0,sizeof(d));                              
         for(int i=0;i<n;i++)
         {
            scanf("%s",w);                                 
            for(int j=0;j<n;j++)
               g[i][j]=w[j]-'0';
         }     
         int c=0;         
         for(int i=0;i<n;i++)                
            for(int j=0;j<n;j++)
               if(!d[i][j] && g[i][j])dfs(i,j),c++;
         
         printf("Image number %d contains %d war eagles.\n",cc++,c);
    }
    return 0;
}




