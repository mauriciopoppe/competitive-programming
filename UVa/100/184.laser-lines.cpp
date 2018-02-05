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

bool taken[301][301];

struct point{
    int x,y;     
    bool operator<(const point &other)const
    {
         if(x != other.x)
             return x < other.x;
         return y < other.y;
    }
};

int cross_product(point &p1, point &p2, point &p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) -
           (p3.x - p1.x) * (p2.y - p1.y);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    point q;
    int i,j,k,l;
    int size;
    while(scanf("%d %d",&q.x,&q.y))
    {
         if(q.x == 0 && q.y == 0)
            break;
         vector<point> p;
         p.push_back(q);         
         while(1)
         {
              scanf("%d %d",&q.x,&q.y);
              if(q.x == 0 && q.y == 0) 
                  break;
              p.push_back(q);
         }
         sort(p.begin(),p.end());
         size = p.size();
         memset(taken,0,sizeof taken);
         
         int f=0;
         for(i = 0; i < size; i++)
         {
             for(j = i + 1; j < size; j++)
             {
                 if(taken[i][j])               
                    continue;
                 vector<int> line; 
                 line.push_back(i);
                 line.push_back(j);
                 int ss = 2;
                 
                 taken[i][j] = taken[j][i] = 1;
                 for(k = j + 1; k < size; k++)
                    if(!taken[j][k] && cross_product(p[i],p[j],p[k]) == 0)
                    {
                       for(l = 0; l < ss; l++)
                          taken[line[l]][k] = taken[k][line[l]] = 1;
                       line.push_back(k);
                       ss++;
                    }
                 
                 int line_size = ss;
                 if(line_size > 2)
                 {
                      if(!f)
                      {
                          printf("The following lines were found:\n");
                          f=1;  
                      }
                      vector<point> sorted;
                      for(k = 0; k < line_size; k++)
                         sorted.push_back(p[line[k]]);
                      sort(sorted.begin(),sorted.end());
                      for(k = 0; k < line_size; k++)
                      {
                          printf("(%4d,%4d)",sorted[k].x,sorted[k].y);                            
                      }
                      printf("\n");
                 }
             }  
         }
         if(!f)
           printf("No lines were found\n");
    }
    return 0;
}
