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

struct point{
       double x,y,r;
       point(double a, double b, double c){x=a;y=b;r=c;}
       };

double d(point &a, point &b)
{
       return sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));       
}

bool intersects(point &a, point &b)
{
     double dab=d(a,b);
     //printf("distance %lf %lf\n",dab,a.r+b.r);
     if(dab>a.r+b.r)return false;
     //printf("a");
     if(dab<=abs(a.r-b.r))return false;
     //printf("b");
     return true;
}

int find(int &n)
{
    if(parent[n]==n)return n;
    return find(parent[n]);    
}

void union_f(int a, int b)
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
    double x,y,r;
    while(scanf("%d",&t) && t>=0)
    {
         vector<point> v;
         for(int i=0;i<=t+2;i++)
         {
               parent[i]=i;
               size[i]=1;  
         }               
         
         for(int i=0;i<t;i++)      
         {
               scanf("%lf%lf%lf",&x,&y,&r);        
               v.push_back(point(x,y,r));
               for(int j=v.size()-2;j>=0;j--)
               {
                     if(intersects(v[i],v[j]))
                     {
                          //printf("%d %d\n",i,j);
                          union_f(i,j);
                     }
               }
               /*
               for(int j=0;j<=t;j++)
               {printf("%d ",parent[j]);}
               printf("\n");
               for(int j=0;j<=t;j++)
               {printf("%d ",size[j]);}
               printf("\n");*/
         }          
         
         int m=0;
         for(int i=0;i<t;i++)
             if(parent[i]==i && size[i]>m)m=size[i];
         
         printf("The largest component contains %d ring",m);     
         if(m!=1)printf("s");
         printf(".\n");    
    }
    return 0;
}
