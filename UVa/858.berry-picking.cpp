#include<stdio.h>
#include<math.h>
#define M 10005
struct point{
       double x, y;
} P[M];

struct line{
       double y, x, b;
} l;

void make_line(int i, int j)
{
     if(P[i].x == P[j].x)
     {
           l.y = 0;
           l.x = 1;
           l.b = -P[i].x;  
     }
     else
     {   
           l.y = 1;
           l.x = (P[j].y - P[i].y) / (P[j].x - P[i].x);
           l.b = P[i].y - P[i].x * l.x; 
     }
}

int main()
{
    int cas, n_points;
    int i, j, k, ind;
    double threshold, x;
    double seg[M];
    scanf("%d", &cas);
    while(cas--)
    {
         scanf("%d", &n_points);
         for(i = 0; i < n_points; ++i)
             scanf("%lf%lf", &P[i].x, &P[i].y);
         scanf("%lf%lf", &threshold, &x);
         
         int ind = 0;
         for(i = 1; i < n_points; ++i)
            if(P[i].y < P[ind].y)
               ind = i;
         int c = 0;
         for(i = ind, j = (ind + 1) % n_points, k = 0; k < n_points; i = j, j = (j + 1) % n_points, ++k)
         {
               if(P[i].x <= x && x <= P[j].x  ||
                  P[j].x <= x && x <= P[i].x)
               {
                    make_line(i, j);
                    if(l.x == 0)
                        seg[c++] = l.b;
                    else
                        seg[c++] = l.x * x + l.b;
               }
         }
         double sum = 0;
         for(i = 0; i < c; i += 2)
             sum += fabs(seg[i] - seg[i + 1]);

         if(sum >= threshold)
             puts("YES");
         else
             puts("NO");
    }
    return 0;
}
