#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 2010
using namespace std;

typedef pair<int,int> pp;
int g[M][M],val[M][M],dx[]={-1,0,0,1},dy[]={0,-1,1,0};
bool d[M][M];

bool check(int x, int y)
{
    if(x>=0 && y>=0 && x<M && y<M)return true;
    return false; 
}

int main()
{
    int w1,w2,x,y;
    while(scanf("%d",&w1) && w1)
    {
         queue<pp> q;   
         memset(val,0,sizeof(val));
         memset(g,0,sizeof(g));              
         for(int i=0;i<w1;i++)
         {
             scanf("%d%d",&x,&y);
             val[x][y]=1;
             q.push(make_pair(x,y));
         }
         
         scanf("%d",&w2);
         for(int i=0;i<w2;i++)
         {
             scanf("%d%d",&x,&y);
             g[x][y]=2;
         }
         int ex=0,ey=0;
         while(!q.empty())
         {
               pp u=q.front();
               q.pop();
               for(int i=0;i<4;i++)
               {
                   x=u.first+dx[i];
                   y=u.second+dy[i];
                   if(check(x,y) && !val[x][y])
                   {
                       val[x][y]=val[u.first][u.second]+1;
                       if(g[x][y]==2){ex=x;ey=y;goto end;}
                       q.push(make_pair(x,y));          
                   }
               }
         }
         
         end:
         printf("%d\n",val[ex][ey]-1);            
    }    
    return 0;
}
