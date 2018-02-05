#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1005
using namespace std;

int dx[]={-1,0,0,1},dy[]={0,-1,1,0},val[M][M],g[M][M],row,col;

bool check(int &x, int &y)
{
     if(x>=0 && y>=0 && x<row && y<col)return true;
     return false;
}

int main()
{
    int mines,i,j,k,sx,sy,ex,ey,x,y,nm;
    while(scanf("%d%d",&row,&col) && row && col)
    {
         memset(val,0,sizeof(val));
         memset(g,0,sizeof(g));
                                            
         scanf("%d",&mines);
         for(k=0;k<mines;k++)
         {
             scanf("%d%d",&i,&nm);
             for(int w=0;w<nm;w++)
             {
                  scanf("%d",&j);
                  g[i][j]=1;   
             }
         }
         scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
         queue<int> qx,qy;
         qx.push(sx);
         qy.push(sy);
         val[sx][sy]=1;
         
         while(!qx.empty())
         {
              int a=qx.front(),b=qy.front();
              qx.pop();
              qy.pop();
              for(k=0;k<4;k++)
              {
                  x=a+dx[k];            
                  y=b+dy[k];
                  if(check(x,y) && !g[x][y] && !val[x][y])
                  {
                       val[x][y]=val[a][b]+1;
                       qx.push(x);         
                       qy.push(y);
                  }
                  if(val[ex][ey])break;
              }             
         }
         if(val[ex][ey]-1>=0) printf("%d\n",val[ex][ey]-1);
         else printf("0\n");
    }
    return 0;
}
