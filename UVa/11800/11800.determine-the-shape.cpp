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
      #define PI 3.141592653589793238
#define EP 1e-5
typedef long long LL;
struct point{
       int x, y;
       bool operator<(const point &a)const
       {
            if(a.x!=x)x<a.x;
            return a.y<a.y;
       }
}v[4];

struct line{
       double y,x,b;
       }ln[12];

void makeLine(point &p1, point &p2, line &l)
{
     if(p1.x==p2.x)
     {
           l.y=0;
           l.x=1;
           l.b=-p1.x;  
     }
     else
     {   
           l.y=1;
           l.x=(p1.y-p2.y)/(p1.x-p2.x);
           l.b=-p1.x*l.x+p1.y; 
     }
}

bool areParalel(line &l1, line &l2)
{
     return fabs(l1.y-l2.y)<=EP && fabs(l1.x-l2.x)<=EP;
}

double d[12];
map<double,int> m;
int size,c;

double dist(point &p1, point &p2)
{
     double dx=p1.x-p2.x;
     double dy=p1.y-p2.y;  
     return sqrt(dx*dx+dy*dy);         
}

bool cmpL(line &l1, line &l2)
{
     if(l1.x==l2.x && l1.y==l2.y && l1.b==l2.b)return true;
     return false;     
}

void calcDist()
{
     int k=0;     
     F(i,4)
       F(j,4)
         if(i!=j)
           d[k]=dist(v[i],v[j]), m[d[k++]]++;     
     size=m.size();
}

bool isSquare()
{
     if(size==2)return true;
     return false;
}

bool isRectangle()
{
     if(size==3)
     {
         TR(m,it)
            if(it->second!=4)return false;
         return true;
     }   
     return false;
}

bool isRhombus()
{
     if(size==3)
     {
          TR(m,it)
             if(it->second==8)return true;
          return false;
     }
     return false;
}

bool isParalel()
{
     map<double,int> x;
     line l1;
     int z=0;
     F(i,4)
       F(j,4)
         if(i!=j)
         {
            makeLine(v[i],v[j],l1);
            int k=0;
            for(k=0;k<z;k++)
               if(cmpL(l1,ln[k]))break;
            if(k==z)ln[z++]=l1;
         }
     c=0;
     //printf("%d\n",z);
     for(int i=0;i<z;i++)
       for(int j=i+1;j<z;j++)
          if(areParalel(ln[i],ln[j]))c++;
     if(c==2)return true;
     return false;
}

bool isTrap()
{
     if(c==1)return true;
     return false;          
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    scanf("%d",&cas);
    F(z,cas)
    {
         m.clear();   
         F(i,4)scanf("%d%d",&v[i].x,&v[i].y);
         //sort(v,v+4);
         calcDist();
         //printf("%d\n",size);
         printf("Case %d: ",z+1);
         if(isSquare())printf("Square");
         else if(isRectangle())printf("Rectangle");
         else if(isRhombus())printf("Rhombus");
         else if(isParalel())printf("Parallelogram");
         else if(isTrap())printf("Trapezium");
         else printf("Ordinary Quadrilateral");
         //printf("%d\n",c);
         NL;
    }
    return 0;
}
