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
#define M 25
int v[1001][M];
int total[M];
char name[M][100];
int valid[M];
int level[1001];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    int n;
    scanf("%d", &cas);
    char w[500];
    while(cas--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
           valid[i] = 1;
        gets(name[0]);
        for(int i = 1; i <= n; ++i)
           gets(name[i]);
        int z = 1;
        while(gets(w) && strlen(w))
        {
            char *ptr = strtok(w, " ");
            int j = 0;
            while(ptr)
            {
                v[z][j++] = atoi(ptr);
                ptr = strtok(NULL, " ");
            }
            ++z;
        }
        
        memset(level, 0, sizeof level);
        memset(total, 0, sizeof total);

        int tied = -1, win = -1;
        if(z == 1) win = 0;
        while(z > 1)
        {
            memset(total, 0, sizeof total);
            for(int i = 1; i < z; ++i)
               ++total[v[i][level[i]]];
            
            //for(int i = 1; i <= n; ++i)
            //   printf("%d ", total[i]);NL;
            
            int mx = -1, mn = 100000;
            for(int i = 1; i <= n; ++i)
               if(valid[i] && total[i] > 0)
                  mx = max(total[i], mx),
                  mn = min(total[i], mn);
            if(mx == mn)
            {
               tied = mn;
               break;
            }
            //printf("%d %d\n", mx, (z - 1) / 2 + 1);
            if(mx >= (z - 1) / 2 + 1)
            {
               win = mx;
               break;
            }
            
            for(int i = 1; i <= n; ++i)
               if(valid[i] && total[i] == mn)
                  valid[i] = 0;
            
            for(int i = 1; i < z; ++i)
               while(!valid[v[i][level[i]]])
                  ++level[i];
        }
        if(win != -1)
        {
           for(int i = 1; i <= n; ++i)
              if(total[i] == win)
                 printf("%s\n", name[i]);
        }
        else if(tied != -1)        
           for(int i = 1; i <= n; ++i)
              if(total[i] == tied)
                 printf("%s\n", name[i]);
                 
        if(cas)NL;                      
    }
    return 0;
}
