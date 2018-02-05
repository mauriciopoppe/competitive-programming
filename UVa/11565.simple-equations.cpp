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

    int A, B, C;
    int cas;
    int x, y, z;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d%d", &A, &B, &C);
        int f = 0, k;
        
        int i;
        for(i = 1; 2 * i <= B; ++i);
                           
        for(i = -i; 2 * i <= B; ++i)
        {
            if(!i)continue;  
            //printf("i = %d\n", i);  
            if(B % abs(i) == 0)
            {
                 x = i;
                 k = B / abs(i);
                 for(int j = i + 1; 2 * j <= k; ++j)
                 {
                    if(!j) continue;
                    if(k % abs(j) == 0)
                    {
                        y = j;
                        z = k / abs(j);
                        if(y == z)
                           continue;
                        //printf("%d %d %d\n", x, y, z);
                        //printf("%d %d\n", x + y + z, x * x + y * y + z * z);
                        //printf("%d %d\n", A, C);
                        if(x + y + z == A && x * x + y * y + z * z == C && x * y * z == B
                           && x != y && x != z && y != z)
                        {
                            f = 1;
                            goto end;
                        }
                    }
                 }
            }
            //printf("here");
        }
        end:
        if(f)
           printf("%d %d %d\n", x, y, z);
        else
           printf("No solution.\n");
    }
    return 0;
}

