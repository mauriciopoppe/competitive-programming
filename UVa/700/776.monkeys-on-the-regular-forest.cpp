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
typedef pair<int,int> ii;
char w[500];
char b[500][500],c;
int m[500][500],cnt;
int mx[500];
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int row,col;

bool check(int &x, int &y)
{
     if(x<0 || y<0 || x==row || y==col)return false;
     return true;     
}

void bfs(int i, int j)
{
     queue<ii > q;
     q.push(ii(i,j));
     m[i][j]=cnt;     
     while(!q.empty())
     {
         ii p=q.front();
         q.pop();
         F(k,8)
         {
              int x=p.first+dx[k], y=p.second+dy[k];
              if(check(x,y) && !m[x][y] && b[x][y]==c)
              {
                   m[x][y]=cnt;
                   q.push(ii(x,y));         
              }
         }
     }          
}

void printB()
{
     F(i,row)
        {F(j,col)
          printf("%c ",b[i][j]);
        NL;}     
}

void print()
{
     F(i,row)
     {
        F(j,col)
        {
           if(j)printf(" ");     
           printf("%*d",mx[j],m[i][j]);
        }
        NL;
     }
     puts("%");
}

int main()
{
    //freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    while(gets(w))
    {
         col=0;
         row=0;
         int s=strlen(w);
         F(i,s)
            if(!isspace(w[i]))
               b[row][col++]=w[i];
         row++;
         while(gets(w) && strcmp(w,"%"))
         {                       
             int j=0;             
             F(i,s)
                if(!isspace(w[i]))
                   b[row][j++]=w[i];                          
             row++;
         }
         //bfs
         memset(m,0,sizeof m);
         cnt=1;
         F(i,row) 
            F(j,col)
               if(!m[i][j])
                  c=b[i][j], bfs(i,j), cnt++; 
         memset(mx,0,sizeof mx);
         F(j,col)
             F(i,row)
                mx[j]=max(mx[j],(int)log10(m[i][j])+1);
         print();
    }
    return 0;
}
