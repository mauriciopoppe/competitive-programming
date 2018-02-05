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
#define M 100001
int st[M+1],size[M+1],aftermv[M+1];
bool mv[M+1];
LL sum[M+1];

int union_f(int n)
{
     while(st[n]!=n)
     {
        st[n]=st[st[n]];            
        n=st[n];
     }
     return n;
}

int fp(int &n)
{
    if(mv[n])
    {
        if(aftermv[n]==st[aftermv[n]])
            return aftermv[n];
        return union_f(st[aftermv[n]]);
    }
    return union_f(n);
}

void print(int n)
{
     FOR(i,1,n+1)
       printf("%d ",st[i]);
         NL;
     //FOR(i,1,n+1)printf("%d ",size[i]);NL;
}

int main()
{
    //freopen("in2.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    /*
    10 100
    2 1 2
    2 2 3
    2 3 1
    1 1 2
    3 1
    3 2
    3 3    
    */
    int n,m,op,to,p,q;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
          for(int i=1;i<=n;++i)
             st[i]=sum[i]=i,size[i]=1,mv[i]=0;
          //print(v);
          F(i,m)
          {
                scanf("%d",&op);
                if(op==1)
                {
                     scanf("%d%d",&p,&q);
                     int x=fp(p),y=fp(q);
                     //printf("%d %d size[x]=%d size[y]=%d\n",x,y,size[x],size[y]);
                     if(x==y)continue;
                     if(size[x]>=size[y])
                     {
                         sum[x]+=sum[y];
                         size[x]+=size[y];
                         st[y]=x;
                     }
                     else
                     {                         
                         sum[y]+=sum[x];
                         size[y]+=size[x];
                         st[x]=y;
                     }
                }
                else if(op==2)
                {
                     scanf("%d%d",&p,&q);
                     int x=fp(p),y=fp(q);
                     if(x==y)continue;
                     sum[y]+=p,
                     sum[x]-=p,
                     mv[p]=1,aftermv[p]=y;
                     --size[x];
                     ++size[y];
                }
                else if(op==3)
                {
                     scanf("%d",&p);
                     int x=fp(p);
                     //printf("[%d]\n",x);
                     printf("%d %lld\n",size[x],sum[x]);
                }
                //print(n);
          }
          //NL;
    }
    return 0;
}
