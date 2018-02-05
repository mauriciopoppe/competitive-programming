#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define M 30
using namespace std;
int parent[M],size[M];
map<char,int> m;

int find(int &n)
{
    if(parent[n]==n)return n;
    return find(parent[n]);    
}

void union_f(int &a, int &b)
{
     int x=find(a),y=find(b);
     if(x==y)return;
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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    char c,a,b;
    scanf("%d",&t);
    getchar();
    getchar();
    for(int k=0;k<t;k++)
    {
         if(k)printf("\n");   
         c=getchar();
         
         int mx=c-'A'+1;
         for(int i=1;i<=mx;i++)
         {
              parent[i]=i;
              size[i]=1;        
         }     
              
         int i=1;     
         m.clear();         
         while(1)
         {
             a=getchar();    
             if(a==EOF)break;
             a=getchar();
             if(a=='\n' || a==EOF)break;
             if(m[a]==0)m[a]=i++;
             b=getchar();
             if(m[b]==0)m[b]=i++;
             union_f(m[a],m[b]); 
         } 
         
         int m=0;
         for(int j=1;j<=mx;j++)
             if(parent[j]==j)m++;        
         printf("%d\n",m);         
    }
    return 0;
}
