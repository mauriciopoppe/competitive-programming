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
int L[100000], R[10000];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int cas;
    int cookies, left;
    scanf("%d", &cas);
    for(int z = 1; z <= cas; ++z)
    {
        scanf("%d%d", &cookies, &left);
        int ate = cookies - left;
        int mid = ate / 2;
        printf("Case #%d:", z);
        if(cookies == left)
        {
           puts(" 0");
           continue;
        }
        int x = 0, y = 0;
        for(int i = 1; i <= sqrt(ate); ++i)
           if(ate % i == 0)
           {
              L[x++] = i;
              if(ate / i != i)
                 R[y++] = ate / i;
           }
        for(int i = 0; i < x; ++i)
           if(L[i] > left)
              printf(" %d", L[i]);
        for(int i = y - 1; i >= 0; --i)
           if(R[i] > left)
              printf(" %d", R[i]);

        /*if(ate > left)
           printf(" %d", ate);*/
        NL;
    }
    return 0;
}
