#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define M 55
using namespace std;
int d[M][M],row,col,counter;
int dx[]={-1,0,0,1},dy[]={0,-1,1,0},x,y;
char g[M][M],temp[M][M];
multiset<int> ms;

bool check(int &i, int &j)
{
     if(i>=0 && i<row && j>=0 && j<col)return true;
     return false;
}

void move(int i, int j)
{
    //move this first
    temp[i][j]=g[i][j];
    g[i][j]='.';
     
    for(int k=0;k<4;k++)
    { 
        x=i+dx[k];
        y=j+dy[k];
        if(check(x,y) && g[x][y]!='.')    
           move(x,y);
    }    
}

void dfs(int i, int j)
{
     d[i][j]=1;
     for(int k=0;k<4;k++)
     {
         x=i+dx[k];
         y=j+dy[k];
         if(check(x,y) && !d[x][y] && temp[x][y]=='X')
             dfs(x,y);    
     }
}

void find()
{
    for(int i=0;i<row;i++)
      for(int j=0;j<col;j++) 
         if(temp[i][j]=='X' && !d[i][j])
           dfs(i,j),counter++;      
}

int main()
{
    int cas=1;
    while(scanf("%d%d",&col,&row) && row && col)
    {                 
         ms.clear();                    
         for(int i=0;i<row;i++)scanf("%s",g[i]);
         
         for(int i=0;i<row;i++)
           for(int j=0;j<col;j++)
              if(g[i][j]=='*' || g[i][j]=='X')
              {
                  memset(d,0,sizeof(d));
                  memset(temp,0,sizeof(temp));            
                  counter=0;            
                  move(i,j);
                  find();
                  ms.insert(counter);                               
              }
                
         
         printf("Throw %d\n",cas++);
         multiset<int>::iterator it=ms.begin();
         printf("%d",*it);
         it++;
         for(;it!=ms.end();it++)
            printf(" %d",*it);
         printf("\n\n");
         
    }
    return 0;
}
