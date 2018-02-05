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

struct let{
        char w;
        int v;
        let(int x, int y){w=x;v=y;}
        bool operator<(const let &x)const
        {
             if(v!=x.v)return v>x.v;
             return w<x.w;
        }
        };
        

int d[M][M],dx[]={-1,0,0,1},dy[]={0,-1,1,0},row,col,x,y,t;
char g[M][M],sp;
vector<let> v;

bool check(int &i, int &j)
{
     if(i>=0 && j>=0 && i<row && j<col)return true;
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
         if(check(x,y) && g[x][y]==sp && !d[x][y])dfs(x,y);
     } 
}

int main()
{
    int n,q=1;
    while(scanf("%d%d",&row,&col) && row && col)
    {
         memset(d,0,sizeof(d));
         v.clear();
              
         for(int i=0;i<row;i++)
            scanf("%s",g[i]);
         
         for(int i=0;i<row;i++)
           for(int j=0;j<col;j++)
              if(!d[i][j] && isalpha(g[i][j]))  
              {
                   sp=g[i][j];
                   t=0;
                   dfs(i,j);
                   v.push_back(let(sp,t));           
              }
         
         sort(v.begin(),v.end());   
         
         printf("Problem %d:\n",q++);
         int s=v.size();
         for(int i=0;i<v.size();i++)
           printf("%c %d\n",v[i].w,v[i].v);
    }
    return 0;
}

