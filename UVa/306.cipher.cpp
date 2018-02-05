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
int encode[201], cycle[201];
char w[205], cp[205];
int main()
{
    int n,k;
    memset(cp,' ',sizeof cp);
    while(scanf("%d",&n) && n)
    {       
        for(int i = 1; i <= n; ++i)
            scanf("%d",&encode[i]);
         
        memset(cycle,0,sizeof cycle);    
        for(int i = 1; i <= n; ++i)
        {
            int t = encode[i];
            while(i != t)
              ++cycle[i], t = encode[t];
            ++cycle[i];
        }
        
        while(scanf("%d",&k) && k)
        {
            getchar();
            gets(w);
            //printf("[%s]\n",w);
            int i = 0;
            for(i = 0; w[i]; ++i);
            for(;i < n ; ++i)
               w[i] = ' ';
            w[i] = cp[i] = '\0';
            for(int i = 1; i <= n; ++i)
            {
                int pos = i;    
                for(int b = 0, c = k % cycle[i]; b < c; ++b)
                   pos = encode[pos];
                cp[pos - 1] = w[i - 1];
            }
            printf("%s\n",cp);
        }
        NL;
    }
    return 0;
}
