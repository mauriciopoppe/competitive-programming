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
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
      #define NL printf("\n")
typedef long long LL;

int a[21][21],b[21][21],c[21][21];

int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};

bool check(int x, int y)
{
     if(x>=1 && y>=1 && x<21 && y<21)return 1;
     return 0;
}

int count(int x, int y)
{
    int c=0;
    F(i,8)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(check(xx,yy) && a[xx][yy])++c;
    }
    return c;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,x,y,year;
    string w,dots (20,'*');
    //F(i,20)
    cin>>t;
    F(k,t)
    {
        memset(a,0,sizeof(a));  
        if(k)printf("\n");  
        cin>>year;
        getchar();
        while(getline(cin,w) && w.size())
        {
             sscanf(w.c_str(),"%d%d",&x,&y);
             a[x][y]=1;                
        }
        
        --year;
        cout<<dots<<endl;
        FOR(i,1,21)
        {  FOR(j,1,21)
             if(a[i][j])putchar('O');
             else putchar(' ');NL;}
        cout<<dots<<endl;
        while(year--)
        {
             memset(b,0,sizeof(b));
             FOR(i,1,21)
               FOR(j,1,21)
                 c[i][j]=count(i,j);
             
             FOR(i,1,21)
               FOR(j,1,21)
               {
                   if(a[i][j])
                   {
                       if(c[i][j]==2 || c[i][j]==3)
                          b[i][j]=1;
                       else
                          b[i][j]=0;
                   }
                   else
                       if(c[i][j]==3)b[i][j]=1;    
               }  
             memcpy(a,b,sizeof(b));
             //cout<<dots<<endl;
             FOR(i,1,21)
             {  FOR(j,1,21)
                if(a[i][j])putchar('O');
                 else putchar(' ');NL;}
             cout<<dots<<endl;                      
        }
    }
    return 0;
}
