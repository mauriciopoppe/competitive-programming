#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 35
using namespace std;

struct point{
       int x,y,z;
       }p;

int g[M][M][M];
int val[M][M][M],l,col,row;
bool d[M][M][M];
int x,y,z;
int dy[]={-1,0,0,1,0,0},dz[]={0,-1,1,0,0,0},dx[]={0,0,0,0,1,-1};

bool check(int &x, int &y, int &z)
{
     if(x>=0 && y>=0 && z>=0 && y<row && z<col && x<l)return true;
     return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char w[M+2];
    int x1,y1,z1,x2,y2,z2,a,b,c;
    while(scanf("%d%d%d",&l,&row,&col) && l && row && col)
    {     
       for(int i=0;i<l;i++)
         for(int j=0;j<row;j++)
         {
             scanf("%s",w);
             for(int k=0;k<col;k++)
             {
                 g[i][j][k]=1;    
                 if(w[k]=='S'){x1=i;y1=j;z1=k;}
                 else if(w[k]=='E'){x2=i;y2=j;z2=k;} 
                 else if(w[k]=='#')g[i][j][k]=0;
             }
         }   
         
         
         memset(val,-1,sizeof(val));
         memset(d,0,sizeof(d));
         //printf("%d\n",val[x2][y2][z2]);
         
         p.x=x1;
         p.y=y1;
         p.z=z1;
         queue<point> q; 
         q.push(p);        
         d[x1][y1][z1]=1;
         val[x1][y1][z1]=0;
         while(!q.empty())
         {
               p=q.front();
               a=p.x;
               b=p.y;
               c=p.z;
               q.pop();
               for(int k=0;k<6;k++)
               {
                    x=a+dx[k];   
                    y=b+dy[k];
                    z=c+dz[k];
                    if(check(x,y,z) && g[x][y][z] && !d[x][y][z])
                    {
                        d[x][y][z]=1;
                        val[x][y][z]=val[a][b][c]+1;
                        p.x=x;
                        p.y=y;
                        p.z=z;
                        q.push(p);           
                    }
               }            
         }   
         if(val[x2][y2][z2]!=-1)printf("Escaped in %d minute(s).\n",val[x2][y2][z2]);
         else printf("Trapped!\n");
    }
    return 0;
}
