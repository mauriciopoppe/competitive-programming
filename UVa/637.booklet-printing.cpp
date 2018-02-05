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

int m[2][3000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    while(scanf("%d", &n) && n)
    {
        int n_pages = (n - 1) / 4 + 1;
        int limit = n_pages * 2;
        int k = 1;
        for(int i = 0; i < limit; ++i)
           if(k <= n)
              m[1][i] = k++;
           else
              m[1][i] = 0;
              
        for(int i = limit - 1; i >= 0; --i)
           if(k <= n)
              m[0][i] = k++;
           else
              m[0][i] = 0;
        printf("Printing order for %d pages:\n", n);
        int page = 1;
        for(int i = 0; i < limit; i += 2, ++page)
        {            
            for(int j = i; j < i + 2; ++j)
            {
               int sum = m[0][j] + m[1][j];
               if(sum)
               {
                    printf("Sheet %d, ", page);  
                    if(!(j & 1))
                    {
                       printf("front: ");
                       if(!m[0][j]) printf("Blank, ");
                       else printf("%d, ", m[0][j]);
                       printf("%d\n", m[1][j]);
                    }
                    else
                    {
                       printf("back : ");
                       printf("%d, ", m[1][j]);
                       if(!m[0][j]) printf("Blank\n");
                       else printf("%d\n", m[0][j]);
                    }
               }
            }
        }
    }
    return 0;
}
