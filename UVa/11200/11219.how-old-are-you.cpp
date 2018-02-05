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
    int cas;
    int x, y, z;
    int day, month, year;
    scanf("%d", &cas);
    F(k, cas)
    {
        scanf("%d/%d/%d", &x, &y, &z);
        scanf("%d/%d/%d", &day, &month, &year);
        int res = z - year;
        if(y < month)
           res--;
        else if(y == month && x < day)
           res--;
        printf("Case #%d: ", k + 1);
        if(res < 0)
           puts("Invalid birth date");
        else if(res > 130)
           puts("Check birth date");
        else printf("%d\n", res); 
    }
    return 0;
}
