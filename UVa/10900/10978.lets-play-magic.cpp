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

int taken[55];
char card[55][55], name[55][55];
char f[55][20];
int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; ++i)
           scanf("%s%s", card[i], name[i]);
        memset(taken, 0, sizeof taken);
        int start = 0;
        for(int i = 0; i < n; ++i)
        {
            while(taken[start])  
               start = (start + 1) % n;
            int size = strlen(name[i]);
            while(1)
            {
                if(!taken[start])
                   --size;
                if(!size)break;  
                start = (start + 1) % n;    
            }
            taken[start] = 1;
            strcpy(f[start], card[i]);
        }
        for(int i = 0; i < n; ++i)
        {
           if(i)putchar(' ');
           printf("%s", f[i]);
        }
        NL;
    }
    return 0;
}
