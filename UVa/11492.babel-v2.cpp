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
#define M 1000
#define N 1000000
#define INF 2000000000
typedef long long LL;
struct node{
       int to,w;
       char s;
       bool operator<(const node& x)const
       {
            return x.w<w;    
       }
};
vector<vector<node> > g;
int d[N],dis[N];
string start,end;

void printG(int n)
{
     for(int i=1;i<=n;i++)
     {
          printf("node %d\n",i);
          TR(g[i],it)
             printf("%c[%d][%d] ",it->s,it->to,it->w);
          NL;
     }     
}

void printD(int n)
{
     for(int i=1;i<=n;i++)
        printf("%d ",d[i]);
     NL;     
}

int main()
{
    vector<node> h;
    char fromS[M],toS[M],word[M];
    int n,s,e;
    node t;
    while(scanf("%d",&n) && n)
    {
         map<string,int> m;
         g.clear();
         g.resize(1);
         
         int k=1,x,y;
         cin>>start>>end;
         
         if(start==end)
         {
              getchar();         
              F(i,n)
                 gets(word);
              printf("0\n");
              continue;
         }
         
         F(i,n)
         {
              scanf("%s%s%s",fromS,toS,word);
              string from(fromS),to(toS);
              if(!(x=m[from]))x=m[from]=k++, g.push_back(h);
              if(!(y=m[to]))y=m[to]=k++; g.push_back(h);              
              t.s=word[0], t.to=y, t.w=strlen(word);
              g[x].push_back(t);
              t.to=x;
              g[y].push_back(t);
         }
         
         if(!(x=m[start]))
         {
            printf("impossivel\n");
            continue;
         }
         else
            s=x;
         
         if(!(x=m[end]))
         {
            printf("impossivel\n");
            continue;
         }
         else
            e=x;
        // printG(k);
         
         //TR(m,it)
         //   cout<<it->first<<" "<<it->second<<endl;
         
         for(int i=1;i<=k;i++)
            dis[i]=0, d[i]=INF;
         
         priority_queue<node> q;
         t.s='-', t.to=s, t.w=0;
         q.push(t);
         d[s]=0;
         
         while(!q.empty())
         {
               node p=q.top();
               //printf("%c %d %d\n",p.s,p.to,p.w);
               q.pop();
               dis[p.to]=1;
               TR(g[p.to],it)
               {
                    if(!dis[it->to] && it->s!=p.s)
                    {
                         int td=p.w+it->w;
                         d[it->to]=min(d[it->to],td);
                         if(d[e]!=INF)goto end;
                         t=*it, t.w=td;
                         q.push(t);
                         //printf(">> %c %d %d\n",t.s,t.to,td);
                    }
               }
               //printD(k);
              // NL;
         }/
         end:
         if(d[e]==INF)printf("impossivel\n");
         else printf("%d\n",d[e]);
    }
    return 0;
}

