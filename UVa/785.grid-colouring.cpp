#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define MR 40
#define MC 90
using namespace std;

char g[MR][MC],sp,gg;
bool d[MR][MC];
int row,col=MC-1,px,py,x,y;
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

bool check(int &i, int &j)
{
     if(i>=0 && j>=0 && i<row && j<MC-1)return true;
     return false;
}

void dfs(int i, int j)
{
     d[i][j]=1;
     g[i][j]=gg;
     for(int k=0;k<4;k++)
     {
         x=i+dx[k];
         y=j+dy[k];
         if(check(x,y) && !d[x][y] && g[x][y]!=sp)dfs(x,y);            
     }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    char w[MC];
    while(1)
    {     
         memset(g,0,sizeof(g));
         memset(d,0,sizeof(d));
         row=0;
         while(1)
         {    
              if(!gets(w))goto end;   
              strcpy(g[row++],w);
              if(w[0]=='_')break;         
         }     
         row--;
         
         for(int i=0;i<row;i++)
         {
           int len=strlen(g[i]);      
           for(int j=0;j<len;j++)
              if(g[i][j]!=' ' && g[i][j]!='\0'){sp=g[i][j];goto l0;}
         }
              
         l0:  
         for(int i=0;i<row;i++)
           for(int j=0;j<MC;j++)
             if(g[i][j]!=sp && g[i][j]!=' ' && g[i][j]!='\0' && !d[i][j]){gg=g[i][j];dfs(i,j);}    
         
         row++;
              
         for(int i=0;i<row;i++)
            printf("%s\n",g[i]);
         
    }end:
    return 0;
}

