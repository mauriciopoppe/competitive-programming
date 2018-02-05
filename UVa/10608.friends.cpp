#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define MAXV 40000
using namespace std;
int parents[MAXV],size[MAXV],n;
    
int find(int n)
{
    if(parents[n]==n)return n;
    return find(parents[n]);    
}

void union_f(int a, int b)
{
     int x=find(a),y=find(b);
     if(x==y)return;
     if(size[x]>=size[y])
     {
         size[x]+=size[y];                    
         parents[y]=x;                
     }     
     else
     {
         size[y]+=size[x];                    
         parents[x]=y;                
     }
}

int main()
{
    int t,n,m,a,b;
    scanf("%d",&t);
    while(t--)
    {
        int s=0;      
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            parents[i]=i;        
            size[i]=1;    
        }      
        
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);                
            union_f(a,b);
        }
        for(int i=0;i<=n;i++)
           if(size[i]>s)s=size[i];
        printf("%d\n",s);
    }
    return 0;
}
