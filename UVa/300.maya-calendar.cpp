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
char names[][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", 
                    "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

char day_names[][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", 
                       "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main()
{
    
    char w[10];
    int cas, year, day;
    scanf("%d", &cas);
    printf("%d\n", cas);
    while(cas--)
    {
        scanf("%d. %s %d", &day, w, &year);
        int days_in_month;
        for(int i = 0; i < 19; ++i)
           if(!strcmp(w, names[i]))
              days_in_month = i * 20;
        int new_date = year * 365 + days_in_month + day;
        
        int new_year = new_date / 260;
        int new_day_name = new_date % 20;
        int new_number = new_date % 13 + 1;
        printf("%d %s %d\n", new_number, day_names[new_day_name], new_year);
        
    }
    return 0;
}
