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
int t[] = {0, 480, 1080, 1320, 480 + 1440, 1080 + 1440, 1320 + 1440, 480 + 1440 * 2};
int rate[] = {2, 0, 1, 2, 0, 1, 2, 0};

double charge[][5] = {{0.10, 0.06, 0.02}, 
                      {0.25, 0.15, 0.05}, 
                      {0.53, 0.33, 0.13},
                      {0.87, 0.47, 0.17},
                      {1.44, 0.80, 0.30}};
                      
char type[3], number[20];
int m[3];
                      
int main()
{
    int sh, sm, eh, em;
    while(scanf("%s", type) && type[0] != '#')
    {
        scanf("%s %d %d %d %d", number, &sh, &sm, &eh, &em);
        int start = sh * 60 + sm, end = eh * 60 + em;
        if(end <= start) end += 1440;
        int remaining = end - start;
        memset(m, 0, sizeof m);
        
        double total = 0;
        int i = 0;
        int ind = type[0] - 'A';
        //printf("%d %d %d\n", start, end, remaining);
        while(remaining)
        {
            //printf("%d [ %d %d ]\n", i, t[i], t[i + 1]);
            if(start >= t[i] && start <= t[i + 1])
            {
                //puts("in");     
                if(start + remaining > t[i + 1])
                {
                    m[rate[i]] += t[i + 1] - start;                    
                    remaining = start + remaining - t[i + 1];
                    total += charge[ind][rate[i]] * (t[i + 1] - start);
                    start = t[i + 1];
                    //printf("%d %d %lf %d\n", m[rate[i]], remaining, total, start);
                    ++i;
                }
                else
                {
                    m[rate[i]] += remaining;
                    total += charge[ind][rate[i]] * remaining;
                    remaining = 0;
                }
            }
            else
               ++i;
            //SP;
        }
        /*for(int i = 1; i < 40; ++i)
           printf("%d", i % 10);NL;*/
        printf("%10s%6d%6d%6d%3s%8.2lf\n", number, m[0], m[1], m[2], type, total);
    }
    return 0;
}
