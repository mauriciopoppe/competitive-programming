#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 9
using namespace std;

bool d[M][M],sides[3];
int g[M][M],t,dx[]={-1,0,0,1},dy[]={0,-1,1,0},sp,x,y;

bool check(int &i, int &j)
{
     if(i>=0 && j>=0 && i<9 && j<9)return true;
     return false;
}

void dfs(int i, int j)
{
     d[i][j]=1;
     t++;
     for(int k=0;k<4;k++)
     {
         x=i+dx[k];
         y=j+dy[k];
         if(check(x,y) && !d[x][y] && g[x][y]==sp)dfs(x,y);            
     }
     t++;
}

void dfs2(int i, int j)
{
     d[i][j]=1;
     t++;
     for(int k=0;k<4;k++)
     {
         x=i+dx[k];
         y=j+dy[k];
         if(check(x,y))
         {
             if(g[x][y])sides[g[x][y]]=1;
             else if(!d[x][y])dfs2(x,y);          
         }            
     }
     t++;
}

int main()
{
    char w[M+1];
    int n,black,white;
    scanf("%d",&n);
    while(n--)
    {
         memset(d,0,sizeof(d));
         memset(g,0,sizeof(g));     
         black=white=0;
         for(int i=0;i<9;i++)
         {     
             scanf("%s",w);
             for(int j=0;j<9;j++)
             {
                 if(w[j]=='O')g[i][j]=1;
                 else if(w[j]=='X')g[i][j]=2;    
             }     
         }
         
         // O's
         sp=1;
         for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
              if(!d[i][j] && g[i][j]==sp){t=0;dfs(i,j);t=(t+1)/2;white+=t;}
              
         // X's
         sp=2;
         for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
              if(!d[i][j] && g[i][j]==sp){t=0;dfs(i,j);t=(t+1)/2;black+=t;}
         
         //unexplored
         for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
              if(!d[i][j])
              {
                  sides[1]=sides[2]=0;        
                  t=0;
                  dfs2(i,j);
                  t=(t+1)/2;
                  if(sides[1] && sides[2])continue;
                  else if(sides[1])white+=t;
                  else black+=t;
              }
         
         printf("Black %d White %d\n",black,white);
    }
    return 0;
}
