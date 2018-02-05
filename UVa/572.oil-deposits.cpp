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
#define M 105
using namespace std;

int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
char g[M][M];
int d[M][M],row,col,a,b;

bool check(int i, int j)
{
     if(i>=0 && i<row && j>=0 && j<col)return true;
     return false;
}

void dfs(int i, int j)
{
    d[i][j]=1;
    for(int k=0;k<8;k++)
    {
        a=i+dx[k];    
        b=j+dy[k];
        if(check(a,b) && !d[a][b] && g[a][b]=='@')dfs(a,b);
    } 
}

int main()
{
    while(scanf("%d%d",&row,&col) && row && col)
    {
         memset(d,0,sizeof(d));                         
         for(int i=0;i<row;i++)
            scanf("%s",g[i]);
         int c=0;
         for(int i=0;i<row;i++)                         
             for(int j=0;j<col;j++)                         
                if(!d[i][j] && g[i][j]=='@')dfs(i,j),c++;
         printf("%d\n",c);
    }
    return 0;
}




