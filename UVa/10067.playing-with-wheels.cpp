#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 11
using namespace std;

struct point{
       int a,b,c,d;
       }s,e,p,temp;

int d[M][M][M][M],da[]={-1,1,0,0,0,0,0,0},db[]={0,0,-1,1,0,0,0,0},dc[]={0,0,0,0,-1,1,0,0},dd[]={0,0,0,0,0,0,-1,1};

int mod10(int x)
{
    if(x<0)x=9;
    if(x==10)x=0;
    return x;
}

int main()
{
    int n,w,x,y,z,cas;
    scanf("%d",&n);
    while(n--)
    {
         scanf("%d%d%d%d%d%d%d%d",&s.a,&s.b,&s.c,&s.d,&e.a,&e.b,&e.c,&e.d);
         scanf("%d",&cas);
         
         memset(d,0,sizeof(d));
         while(cas--)     
         {
              scanf("%d%d%d%d",&w,&x,&y,&z);
              d[w][x][y][z]=-1;            
         }                  
         queue<point> q;
         q.push(s);
         
         if(d[s.a][s.b][s.c][s.d]==-1){printf("-1\n");continue;}
         d[s.a][s.b][s.c][s.d]=1;
         
         while(!q.empty())
         {
               temp=q.front();
               q.pop();
               for(int k=0;k<8;k++)
               {
                    w=mod10(temp.a+da[k]);   
                    x=mod10(temp.b+db[k]);
                    y=mod10(temp.c+dc[k]);
                    z=mod10(temp.d+dd[k]);
                    if(!d[w][x][y][z])
                    {
                         d[w][x][y][z]=d[temp.a][temp.b][temp.c][temp.d]+1;
                         if(temp.a==e.a && temp.b==e.b && temp.c==e.c && temp.d==e.d)goto end;
                         p.a=w;
                         p.b=x;
                         p.c=y;
                         p.d=z;
                         q.push(p);
                    }                                        
               }           
         }         
         
         end:
         if(d[e.a][e.b][e.c][e.d] && d[e.a][e.b][e.c][e.d]!=-1)printf("%d\n",d[e.a][e.b][e.c][e.d]-1);
         else printf("-1\n");
    }
    
    return 0;
}

