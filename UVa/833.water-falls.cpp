#include <stdio.h>
#include <stdlib.h>
int n_segments, n_query, t;
struct segment {
   int x1, y1, x2, y2, min_x, max_x;
} S[100];

int cmp(const void *a, const void *b) 
{
    struct segment *aa = (struct segment *) a;
    struct segment *bb = (struct segment *) b;
    return aa->y2 < bb->y2;
}

int main() 
{
   int cas, i, z;
   scanf("%d", &cas);
   for(z = 0; z < cas; ++z)
   {
      if(z)putchar(10);   
      scanf("%d", &n_segments);
      for (i = 0; i < n_segments; ++i)
      {
         scanf("%d %d %d %d", &S[i].x1, &S[i].y1, &S[i].x2, &S[i].y2);
         if (S[i].y1 > S[i].y2) 
         {
             t = S[i].y1, S[i].y1 = S[i].y2, S[i].y2 = t,
             t = S[i].x1, S[i].x1 = S[i].x2, S[i].x2 = t;
         }
         S[i].min_x = S[i].x1 < S[i].x2 ? S[i].x1 : S[i].x2;
         S[i].max_x = S[i].x1 > S[i].x2 ? S[i].x1 : S[i].x2;
      }
      qsort(S, n_segments, sizeof(struct segment), cmp);
      scanf("%d", &n_query);
      while (n_query--)
      {
         int x, y;
         scanf("%d%d", &x, &y);
         for (i = 0; i < n_segments; ++i)
            if (y > S[i].y1 && S[i].min_x <= x && x <= S[i].max_x) 
            {
               x = S[i].x1;
               y = S[i].y1;
            }
         printf("%d\n", x);
      }
   }
   return 0;
}
