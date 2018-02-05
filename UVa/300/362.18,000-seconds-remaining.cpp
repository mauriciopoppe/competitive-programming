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
   // freopen("out.txt","w",stdout);

    int total, k;
    int cas = 1;
    while(scanf("%d", &total) && total)
    {
        int sum = 0;
        int partial = 0;
        double remain;
        int i = 0;
        int total_time = 0;
        printf("Output for data set %d, %d bytes:\n", cas++, total);
        while(sum != total)
        {
            scanf("%d", &k);
            sum += k;
            partial += k;
            i++;
            if(i == 5)
            {
                 printf("   Time remaining: ");
                 if(partial)                 
                 {
                    remain = (5.0 * (double) (total - sum)) / ((double)partial);
                    partial = 0;
                    printf("%.0lf seconds\n", ceil(remain));
                 }
                 else puts("stalled");
                 i = 0;
            }
            ++total_time;
        }
        printf("Total time: %d seconds\n\n", total_time);
    }
    return 0;
}
