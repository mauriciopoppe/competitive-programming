#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define MAXV 100010
using namespace std;
int parent[MAXV],size[MAXV],n;
map<string,int> m;
int s=0;
                  
int find(int &n)
{
    if(parent[n]==n)return n;
    return find(parent[n]);    
}

void union_f(int &a, int &b)
{
     int x=find(a),y=find(b);
     if(x==y)
     {
          printf("%d\n",size[x]); 
          return;         
     }
     if(size[x]>=size[y])
     {
          size[x]+=size[y];
          parent[y]=x;                    
          printf("%d\n",size[x]);         
     }
     else
     {
          size[y]+=size[x];
          parent[x]=y;    
          printf("%d\n",size[y]);         
     }            
     
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         int n,j=1;
         m.clear();
         string a, b;
         scanf("%d",&n);
         int ss=2*n;
         if(ss>100000)ss=100000;
         for(int i=1;i<=ss;i++)
         {
              parent[i]=i;
              size[i]=1;        
         }
         for(int i=0;i<n;i++)
         {
              cin>>a>>b;
              if(m[a]==0){m[a]=j;j++;}
              if(m[b]==0){m[b]=j;j++;}    
              //printf("%d %d\n",m[a],m[b]);  
              union_f(m[a],m[b]);
         }          
    }
    return 0;
}
