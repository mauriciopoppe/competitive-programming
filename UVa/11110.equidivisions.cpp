#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<sstream>
#define M 105
using namespace std;

bool d[M][M],sides[3];
int g[M][M],t,dx[]={-1,0,0,1},dy[]={0,-1,1,0},sp,x,y,n,f;

bool check(int &i, int &j)
{
     if(i>=0 && j>=0 && i<n && j<n)return true;
     return false;
}

void dfs(int i, int j)
{
     d[i][j]=1;
     ++t;
     for(int k=0;k<4;k++)
     {
         x=i+dx[k];
         y=j+dy[k];
         if(check(x,y) && !d[x][y] && g[x][y]==sp)dfs(x,y);            
     }
     ++t;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string w,buf1,buf2;
    while(scanf("%d",&n) && n)
    {
         getchar();                
         memset(d,0,sizeof(d));
         memset(g,0,sizeof(g));     
        
         for(int i=1;i<n;i++) 
         {
             getline(cin,w);
             stringstream ss(w);      
             while(ss>>buf1>>buf2)
             {
                 x=atoi(buf1.c_str());
                 y=atoi(buf2.c_str());
                 g[--x][--y]=i;    
             }     
         }
         
         f=1;
         for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
              if(!d[i][j])
              {
                 sp=g[i][j];                                   
                 t=0;
                 dfs(i,j);
                 t=(t+1)/2;
                 if(t!=n){f=0;goto l1;}
              }
         
         l1: 
         if(f) printf("good\n");
         else printf("wrong\n");
    }
    return 0;
}
