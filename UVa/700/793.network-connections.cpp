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
int parent[MAXV],size[MAXV],n;

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
    int t;
    scanf("%d",&t);
    for(int q=0;q<t;q++)
    {
         if(q)printf("\n");   
         int good=0,bad=0,c;
         int a,b;
         char car;
         scanf("%d",&c);
         
         for(int i=1;i<=c;i++)
         {
             parent[i]=i;
             size[i]=1;        
         }
         
         while(1)
         {
              getchar();   
              car=getchar();           
              if(car=='\n' || car==EOF)break;
              scanf("%d%d",&a,&b);
              if(car=='c')
                 union_f(a,b);
              else 
                 if(find(a)==find(b))good++;
                 else bad++;   
         }          
         printf("%d,%d\n",good,bad);
    }
    //system("pause");
    return 0;
    
}
