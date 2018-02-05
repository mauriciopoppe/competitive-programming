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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n, last, next;
    char w1[500], w2[500];
    int cas = 1;
    while(scanf("%d", &n) && n)
    {
        scanf("%d", &last);
        int c = 1;
        printf("Case %d:\n", cas++);
        for(int i = 1; i < n; ++i)
        {
            scanf("%d", &next);
            if(next == last + c)
                ++c;
            else 
            {                 
                printf("0%d", last);
                if(c > 1)
                {
                    putchar('-'); 
                    sprintf(w1, "%d", last);
                    sprintf(w2, "%d", last + c - 1);
                    int j = 0;
                    for(j = 0; w1[j] == w2[j]; ++j);
                    for(; w2[j]; putchar(w2[j++]));   
                    c = 1;
                }
                last = next;
                NL;
            }
        }
        printf("0%d", last);
        if(c > 1)
        {
            putchar('-'); 
            sprintf(w1, "%d", last);
            sprintf(w2, "%d", last + c - 1);
            int j = 0;
            for(j = 0; w1[j] == w2[j]; ++j);
            for(; w2[j]; putchar(w2[j++]));
        }
            
        NL;
        NL;
    }
    return 0;
}
