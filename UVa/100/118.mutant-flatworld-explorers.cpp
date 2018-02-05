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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

map<char,int> m;
int x,y,v;
int t[51][51];

char getP()
{
    if(!v)return 'N';
    if(v==1)return 'E';
    if(v==2)return 'S';
    return 'W';
}

void move()
{
     if(!v)y++;
     else if(v==1)x++;
     else if(v==2)y--;
     else x--;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    m['N']=0;
    m['E']=1;
    m['S']=2;
    m['W']=3;
    int row,col;
    scanf("%d%d",&row,&col);
    char w[105];
    char h;    
    while(cin>>x>>y>>h)
    {
        v=m[h];               
        scanf("%s",w);
        int s=strlen(w),lx,ly;
        bool f=0;
        for(int i=0;i<s;i++)
        {
            if(w[i]=='F')
            {
               lx=x;
               ly=y;          
               move();
               if(x<0 || x>row || y<0 || y>col)
               {
                     if(!t[lx][ly]) 
                     {
                         f=1;
                         t[lx][ly]=1;
                         break;                   
                     }
                     else{ x=lx;y=ly;}
               }
            }
            else if(w[i]=='L')
            {
                v--;
                if(v<0)v=3;
            }
            else if(w[i]=='R')
                v=(v+1)%4;
            
            //printf(" %d %d %c\n",x,y,getP());
        }
        if(f) printf("%d %d %c LOST\n",lx,ly,getP());
        else printf("%d %d %c\n",x,y,getP());
    }
    return 0;
}
