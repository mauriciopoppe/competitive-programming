#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 205
using namespace std;
int d[M][M],dx[]={-1,-1,0,0,1,1},dy[]={-1,0,-1,1,0,1},f,n,x,y,won;
bitset<M> b;
char g[M][M];

bool check(int i, int j)
{
     if(i>=0 && i<n && j>=0 && j<n)return true;
     return false;
}

void dfs(int i, int j)
{
     d[i][j]=1;
     if(f) b[i]=1;
     else b[j]=1;
     for(int k=0;k<6;k++)
     {
         x=i+dx[k];
         y=j+dy[k];    
         if(check(x,y) && !d[x][y])
         {
              if(f && g[x][y]=='b')dfs(x,y);
              else if(!f && g[x][y]=='w')dfs(x,y);                       
         }                      
     }
}

int main()
{
    int cc=1;
    while(scanf("%d",&n) && n)
    {
         memset(d,0,sizeof(d));                
         for(int i=0;i<n;i++)
           scanf("%s",g[i]);
         b.reset();
         //scan b
         f=1;
         won=-1;
         for(int i=0;i<n;i++)
           for(int j=0;j<n;j++)
             if(!d[i][j] && g[i][j]=='b')
             {
                 dfs(i,j);                
                 if(b.count()==n){won=0;goto end;}
                 b.reset();
             }
         
         f=0;
         for(int i=0;i<n;i++)
           for(int j=0;j<n;j++)
             if(!d[i][j] && g[i][j]=='w')
             {
                 dfs(i,j);                
                 if(b.count()==n){won=1;goto end;}
                 b.reset();
             }
             
         end:
         printf("%d ",cc++);
         if(!won)printf("B\n");
         else printf("W\n");                      
    }
    return 0;
}
