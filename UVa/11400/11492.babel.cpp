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
#define N 10000
#define INF 2000000000
#define MINF 127
typedef long long LL;
struct node{
       int to,w;
       char c;
       bool operator<(const node& x)const
       {
            return x.w<w;    
       }
};
node g[6005][4005];
int d[N][27],size[N];
string start,end;

/*void printG(int n)
{
     for(int i=1;i<=n;i++)
     {
          printf("node %d\n",i);
          TR(g[i],it)
             printf("%c[%d][%d] ",it->s,it->to,it->w);
          NL;
     }     
}
*/
void printD(int e)
{
     for(int i=0;i<26;i++)
        printf("%d ",d[e][i]);
     NL;     
}

int main()
{
    string from,to,word;
    int n,s,e,td;
    node t;
    while(scanf("%d",&n) && n)
    {
         map<string,int> m;         
         int k=1,x,y;
         cin>>start>>end;
         memset(size,0,sizeof size);
         
         F(i,n)
         {
              cin>>from>>to>>word;
              if(!(x=m[from]))x=m[from]=k++;
              if(!(y=m[to]))y=m[to]=k++;              
              t.c=word[0], t.to=y, t.w=word.size();
              g[x][size[x]++]=t;
              t.to=x;
              g[y][size[y]++]=t;
         }
         
         if(!(s=m[start]))
         {
            printf("impossivel\n");
            continue;
         }
         
         if(!(e=m[end]))
         {
            printf("impossivel\n");
            continue;
         }
         // printG(k);
         
         //TR(m,it)
         //   cout<<it->first<<" "<<it->second<<endl;
         
         for(int i=1;i<=k;i++)
            memset(d[i],MINF,sizeof d[i]);
         
         priority_queue<node> q;
         t.c='{', t.to=s, t.w=0;
         q.push(t);
         memset(d[s],0,sizeof d[s]);
               //printD(e);
         
         while(!q.empty())
         {
               node p=q.top();
               //printf("%c %d %d\n",p.c,p.to,p.w);
               q.pop();               
               if(p.to==e)break;
               F(i,size[p.to])
               {                              
                    node *it=&g[p.to][i];                                              
                    //printf(">>%c %d %d\n",it->c,it->to,it->w);

                    if(p.c!=it->c)
                    {
                         //printf("no same letter %c[%d] %c[%d]\n",p.c,(int)p.c-'a',it->c,(int)it->c-'a');         
                         td=d[p.to][p.c-'a']+it->w;
                         if(td<d[it->to][it->c-'a'])
                         {
                             //printf("%d %d\n",d[it->to][it->c],td);                   
                             d[it->to][it->c-'a']=td;                         
                             t=*it, t.w=td;
                             //printf("IN %c %d %d\n",t.c,t.to,t.w);
                             q.push(t);
                         }
                    }
                    //SP;
               }
               //printD(e);
               //SP;
               //NL;
         }
         end:
         int mn=INF;
         F(i,26)
            if(d[e][i]<mn)mn=d[e][i];    
            
         if(mn==INF)printf("impossivel\n");
         else printf("%d\n",mn);
    }
    return 0;
}
