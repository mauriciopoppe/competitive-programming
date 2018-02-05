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
struct signal{
       double length;
       double green, yellow, red;
       double total;
} s[10];

int try_to_solve(int i, double t)
{
    int k = (int) (t / s[i].total);
    t -= k * s[i].total;
    //printf("t = %lf\n", t);
    if(t <= s[i].green + s[i].yellow)
       return 1;
    return 0;
}

int res[50];

int main()
{
    int n, cas = 1;
    while(scanf("%d", &n) && n != -1)
    {
        for(int i = 0; i < n; ++i)
            scanf("%lf%lf%lf%lf", &s[i].length, &s[i].green, &s[i].yellow, &s[i].red),
            s[i].total = s[i].green + s[i].yellow + s[i].red;

        printf("Case %d:", cas++);            
        int size = 0;
        for(int speed = 30; speed <= 60; ++speed)
        {
            double speed_ms = (double) speed / 3600.0;                        
            int f = 1;
            for(int i = 0; i < n && f; ++i)
            {
                double t = s[i].length / speed_ms;
                //printf("%lf %lf %.15lf\n", speed_ms, t, t * speed_ms);
                //SP;
                f = try_to_solve(i, t);
            }
            if(f)
               res[size++] = speed;
        }
        if(size)
        {
            int start, end;
            for(int i = 0; i < size;)
            {
               if(i)putchar(',');     
               start = res[i], end = 0;
               while(++i < size && res[i] == res[i - 1] + 1)
                   end++;
               if(!end)
                   printf(" %d", start);
               else
                   printf(" %d-%d", start, start + end);
            }
            NL;            
        }
        else puts(" No acceptable speeds.");
    }
    return 0;
}
