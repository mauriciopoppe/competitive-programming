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
#define TM 10 
using namespace std;

int d[M][M],t,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1},col,row,x,y;
int val[M][M];
char g[M][M];

bool check(int i, int j)
{
     if(i>=0 && j>=0 && i<row && j<col)return true;
     return false;
}

void print()
{
     for(int i=0;i<20;i++)
     {for(int j=0;j<20;j++)printf("%d ",val[i][j]);printf("\n");}           
}

void dfs(int i, int j)
{
     d[i][j]=TM;
     t++;
     for(int k=0;k<8;k++)
     {
         x=i+dx[k];
         y=j+dy[k];
         if(check(x,y) && g[x][y]=='W' && !d[x][y])dfs(x,y);    
     }
     t++;
}

void mark(int i, int j)
{
     val[i][j]=t;
     d[x][y]=1;
     for(int k=0;k<8;k++)
     {
         x=i+dx[k];
         y=j+dy[k];
         if(check(x,y) && d[x][y]==TM)mark(x,y);    
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
         memset(d,0,sizeof(d));  
         memcpy(val,d,sizeof(d));
         memset(g,0,sizeof(g));   
         row=col=0;          
         while(1)
         {
             gets(w);
             if(sscanf(w,"%d %d",&i,&j)==2)break;          
             strcpy(g[row++],w);
         }
           
         col=strlen(g[0]);
         //print();
         while(1)
         {
              if(sscanf(w,"%d %d",&i,&j)!=2)break;
              i--;
              j--;
              //printf("%d %d\n",i,j);
              if(g[i][j]=='W' && !d[i][j])
              { 
                  t=0;
                  dfs(i,j);
                  t=(t+1)/2;
                  mark(i,j);
              }
              printf("%d\n",val[i][j]); 
              if(!gets(w))break; 
              if(strlen(w)==0)break;
         }   
         //print();
    }
    return 0;
}
