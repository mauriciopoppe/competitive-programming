#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 105
using namespace std;

int d[M][M],t,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1},col,row,x,y;
char g[M][M];

bool check(int i, int j)
{
     if(i>=0 && j>=0 && i<row && j<col)return true;
     return false;
}

void dfs(int i, int j)
{
     d[i][j]=1;
     for(int k=0;k<8;k++)
     {
         x=i+dx[k];
         y=j+dy[k];
         if(check(x,y) && g[x][y]=='W' && !d[x][y])dfs(x,y);    
     }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int i,j,cas;
    char w[M+1];
    scanf("%d",&cas);
    getchar();
    getchar();
    for(int q=0;q<cas;q++)
    {
         if(q)printf("\n"); 
         memset(g,0,sizeof(g));   
         row=col=0;          
         while(1)
         {
             gets(w);
             if(w[0]!='L' && w[0]!='W')break;          
             strcpy(g[row++],w);
         } 
         col=strlen(g[0]);
         
         while(1)
         {
              if(sscanf(w,"%d%d",&i,&j)!=2)break;
              i--;
              j--;
              memset(d,0,sizeof(d));
              if(g[i][j]=='W')dfs(i,j);
              int c=0;
              for(int k=0;k<row+1;k++)
                for(int l=0;l<col+1;l++)
                   if(d[k][l] && g[i][j]=='W')c++;                                
              printf("%d\n",c); 
              
              if(!gets(w))break;
              if(strlen(w)==0)break;
         }   
         //print();
    }
    return 0;
}
