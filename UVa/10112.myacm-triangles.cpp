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
struct point{
       int x, y;
};

int A;
int cross_product(point &p1, point &p2, point &p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - 
           (p3.x - p1.x) * (p2.y - p1.y);
}

bool point_inside_triangle(point &p1, point &p2, point &p3, point &check)
{
     //A is the area of the triangle
     //a1, a2, a3 are the three little areas
     int a1, a2, a3;
     //A = abs(cross_product(p1,p2,p3));
     a1 = abs(cross_product(check,p1,p2));
     a2 = abs(cross_product(check,p2,p3));
     a3 = abs(cross_product(check,p1,p3));
     if(abs(A - a1 - a2 - a3) == 0)
        return 1;
     return 0;
}

int main()
{
    int n;
    char result[4], c;
    result[3] = '\0';
    while(scanf("%d", &n) && n)
    {
         vector<point> P(n);
         for(int i = 0; i < n; ++i)
             scanf("%*s %d %d", &P[i].x, &P[i].y);
         
         int max_area = 0;         
         for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
               for(int k = j + 1; k < n; ++k)
               {
                   A = abs(cross_product(P[i], P[j], P[k]));
                   int l = 0;
                   for(l = 0; l < n; ++l)
                       if(l == i || l == j || l == k)
                           continue;
                       else if(point_inside_triangle(P[i], P[j], P[k], P[l]))
                           break;
                           
                   if(l == n && A > max_area)
                   {
                       max_area = A;
                       //printf("%d %d %d\n", i, j, k);
                       result[0] = i + 'A';
                       result[1] = j + 'A';
                       result[2] = k + 'A';
                   }
               }
         printf("%s\n", result);
    }
    return 0;
}
