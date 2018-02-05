#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;

struct point{
       int x, y;
       point(int a, int b){x=a;y=b;}
       };
       
vector<point> a;
bool b[21];
int n,M;

void bt(int c, vector<point> A)
{
     if(c==n)    
     {     
            //printf("aaaaaaaaaaaa\n");            
            int path=0;     
            for(int i=0;i<c;i++)                 
                path+=abs(A[i].x-A[i+1].x)+abs(A[i].y-A[i+1].y);
            path+=abs(A[0].x-A[c].x)+abs(A[0].y-A[c].y);
            //printf("%d\n",path);
            if(path<M)M=path;
     } 
     else
     {
         //printf("%d\n",c);
         for(int i=1;i<=n;i++)    
            if(!b[i])
            {
                 b[i]=1;
                 A.push_back(a[i]);
                 bt(c+1,A);
                 b[i]=0;     
                 A.pop_back();    
            }
     }
}

int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
          M=999999999;    
          a.clear();
          scanf("%d%d%d%d",&x,&y,&x,&y);
          a.push_back(point(x,y));
          
          scanf("%d",&n);
          fill(b,b+21,false);
          b[0]=1;
          vector<point> A;
          A.push_back(a[0]);
          
          for(int i=0;i<n;i++)
          {
               scanf("%d%d",&x,&y);
               a.push_back(point(x,y));        
          }
          
          
          //printf("%d %d %d %d\n",a[0].x,a[0].y,a[1].x,a[1].y);
          bt(0,A);
          printf("The shortest path has length %d\n",M);              
    }
    return 0;
}
