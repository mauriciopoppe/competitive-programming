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
int d[102];
bool dis[102];
vector<vector<int> > g;
int main()
{
    int cas,n;
    string w;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d",&n);
         getchar();
         g.clear();
         g.resize(n+1);
         F(i,n)
         {
               getline(cin,w);
               stringstream ss(w);
               string buf;
               while(ss>>buf)
               {
                    g[i+1].push_back(atoi(buf.c_str()));         
               }
         }
         int best=-1;
         double dist=2000000000;
         F(i,n)
         {
             int k=i+1;
             queue<int> q;
             q.push(k);
             memset(dis,0,sizeof dis);          
             //memset(d,0,sizeof d);
             d[k]=0;
             dis[k]=1;
             while(!q.empty())
             {
                  int x=q.front();
                  q.pop();
                  TR(g[x],it)
                  {
                       if(!dis[*it])
                       {
                            dis[*it]=1;
                            d[*it]=d[x]+1;
                            q.push(*it);      
                       }      
                  }
             }
             double t=0;
             for(int j=1;j<=n;j++)
                   if(j!=k)
                      t+=d[j];
             if(t<dist)
             {
                 dist=t;
                 best=k;      
             }
         }
         printf("%d %lf\n",best,dist/(double)n);
    }    
    return 0;
}
