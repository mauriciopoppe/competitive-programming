#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define MAXV 50001
using namespace std;
int parent[MAXV],size[MAXV];

int find(int &n)
{
    if(parent[n]==n)return n;
    return find(parent[n]);    
}

void union_f(int &a, int &b)
{
     int x=find(a),y=find(b);
     if(x==y)
         return;
     if(size[x]>=size[y])
     {
          size[x]+=size[y];
          parent[y]=x;                    
     }
     else
     {
          size[y]+=size[x];
          parent[x]=y;    
     }            
     
}


int main()
{
    int t,n,m,a,b,q=1;
    while(scanf("%d%d",&n,&m) && n && m)
    {
          for(int i=1;i<=n;i++)
          {
               parent[i]=i;
               size[i]=1;        
          }      
          
          for(int i=0;i<m;i++)
          {
               scanf("%d%d",&a,&b);
               union_f(a,b);        
          }
          
          int rel=0;
          for(int i=1;i<=n;i++)
            if(i==parent[i])rel++;
          printf("Case %d: %d\n",q++,rel);  
    }
    return 0;
}
