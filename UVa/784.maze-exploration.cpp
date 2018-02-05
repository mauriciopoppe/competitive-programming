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

char g[MR][MC];
bool d[MR][MC];
int row,col=MC-1,px,py,x,y;
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

bool check(int &i, int &j)
{
     if(i>=0 && j>=0 && i<row-1 && j<MC-1)return true;
     return false;
}

void dfs(int i, int j)
{
     d[i][j]=1;
     g[i][j]='#';
     for(int k=0;k<4;k++)
     {
         x=i+dx[k];
         y=j+dy[k];
         if(check(x,y) && !d[x][y] && g[x][y]==' ')dfs(x,y);            
     }
}

int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    int n;
    char w[MC];
    scanf("%d",&n);
    getchar();
    while(n--)
    {     
         memset(g,' ',sizeof(g));
         memset(d,0,sizeof(d));
         row=0;
         while(gets(w))
         {       
              strcpy(g[row],w);
              g[row++][strlen(w)]=' ';
              if(w[0]=='_')break;         
         }     
         
         for(int i=0;i<row;i++)
           for(int j=0;j<MC;j++)
             if(g[i][j]=='*'){px=i;py=j;goto l1;}    
         
         l1:
         //dfs
         g[px][py]=' ';
         dfs(px,py);         
         
         for(int i=0;i<row;i++)
           for(int j=MC-1;j>=0;j--)
           {
              if(g[i][j]!=' '){g[i][j+1]='\0';break;}
              else if(!j)g[i][0]='\0';
           }
              
         for(int i=0;i<row;i++)
            printf("%s\n",g[i]);
         
    }
    return 0;
}
