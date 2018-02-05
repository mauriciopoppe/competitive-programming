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
#define M 11
char m[M][M],r[M][M];
int n;
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
bool f=0;
bool check(int &x, int &y)
{
     if(x<0 || y<0 || x==n || y==n)return false;
     return true;     
}

void fill()
{
     F(i,n)
        F(j,n)
           if(r[i][j]=='x')
           {
               if(m[i][j]=='*')r[i][j]='*';
               else
               {   
                   int w=0;         
                   F(k,8)
                   {
                       int x=i+dx[k],y=j+dy[k];  
                       if(check(x,y) && m[x][y]=='*')
                          w++;
                   }
                   r[i][j]=(char)(w+'0');
               }
           }
           else if(m[i][j]=='*' && f)
              r[i][j]='*';
}

int main()
{
    int cas;
    scanf("%d",&cas);
    F(z,cas)
    {
         if(z)NL;        
         f=0;
         scanf("%d",&n);
         F(i,n)
            scanf("%s",m[i]);
         F(i,n)
         {               
            scanf("%s",r[i]);
            if(!f)
                F(j,n)
                   if(r[i][j]=='x' && m[i][j]=='*')
                   {f=1;break;}
         }
         fill();
         F(i,n)
            printf("%s\n",r[i]);
    }
    return 0;
}
