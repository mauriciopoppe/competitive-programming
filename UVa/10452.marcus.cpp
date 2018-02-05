#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 10
char lk[]={"IEHOVA#"},dir[M];
char m[M][M];
int row,col;
int dx[]={-1,0,0},dy[]={0,-1,1},f;
char moves[]={"flr"};

bool check(int x, int y)
{
     if(x<0 || y<0 || x==row || y==col)return false;
     return true;     
}

void bt(int n, int start, int end)
{
     if(f)return;
     if(n==7)f=1;
     else
     {
         for(int i=0;i<3;i++)
         {
             int x=start+dx[i],y=end+dy[i];
             if(check(x,y) && m[x][y]==lk[n])
             {                           
                 dir[n]=moves[i];
                 //printf("%d %d %c %c\n",x,y,m[x][y],dir[n]);
                 //SP;
                 bt(n+1,x,y);
             }
         }
     }
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d%d",&row,&col);
         getchar();
         int start,end;
         F(i,row)
         {
            gets(m[i]);     
            F(j,col)
               if(m[i][j]=='@')start=i,end=j;
         }
         f=0;
         //printf("%d %d\n",start,end);
         bt(0,start,end);
         F(i,7)
         {
             if(i)printf(" ");
             if(dir[i]=='f')printf("forth");
             else if(dir[i]=='l')printf("left");
             else printf("right");  
         }
         NL;
    }
    return 0;
}
