#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 301
#define INF 999999999
using namespace std;

char g[M][M];
int d[M][M][4],row,col;
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

bool check(int x2, int y2, int x1, int y1)
{
    //printf("%d %d\n",x2,y2); 
    if(x2>=0 && x2<row && y2>=0 && y2<col)
    {  
           if(x1==x2)
           {
               if(y1>y2)
               {   
                   for(int k=y1;k>=0 && k>=y2;k--)   
                   if(g[x1][k]=='#')return false;
                   return true;
               }
               else
               {
                   for(int k=y1;k<col && k<=y2;k++)
                   if(g[x1][k]=='#')return false;
                   return true;
               }    
           }
           else
           {
               //printf("[[ 2 ]]\n");
               if(x1>x2)
               {
                   for(int k=x1;k>=0 && k>=x2;k--) 
                   if(g[k][y1]=='#')return false;
                   return true;
               }           
               else
               {
                   for(int k=x1;k<row && k<=x2;k++)   
                   if(g[k][y1]=='#')return false;
                   return true;
               }           
           }           
    }
    return false; 
}

int mod3(int x)
{
    ++x;
    if(x==4)x=1;
    return x;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,sx,sy,ex,ey;
    scanf("%d",&n);
    while(n--)
    {
         scanf("%d%d",&row,&col);
         for(int i=0;i<row;i++)
         {
            scanf("%s",g[i]);
            for(int j=0;j<col;j++)
            {
                if(g[i][j]=='S'){sx=i;sy=j;}
                else if(g[i][j]=='E'){ex=i;ey=j;}    
            }
         }
         
         queue<int> qx,qy,ql;
         memset(d,0,sizeof(d));
         qx.push(sx);
         qy.push(sy); 
         ql.push(1);
         
         while(!qx.empty())
         {
              int a=qx.front(),b=qy.front(),len=ql.front();
              int nl=mod3(len);
              //printf("\n%d %d - %d\n",a,b,len);
              qx.pop();
              qy.pop();
              ql.pop();
              
              //get positions according to limit
              for(int k=0;k<4;k++)
              {
                   //get right directions
                   int x=a+dx[k]*len,y=b+dy[k]*len;
                   //printf("[%d %d %d %d]\n",a,b,x,y);
                   if(check(x,y,a,b) && !d[x][y][nl])
                   {           
                       //printf("IN %d %d - %d\n",x,y,nl);              
                       d[x][y][nl]=d[a][b][len]+1;
                       qx.push(x);
                       qy.push(y);
                       ql.push(nl);
                   }
              }                           
         }
         
         int mn=INF;
         for(int i=1;i<=3;i++)
            if(d[ex][ey][i])mn<?=d[ex][ey][i];
         
         if(mn!=999999999)printf("%d\n",mn);
         else printf("NO\n");
         
    }
    return 0;
}
