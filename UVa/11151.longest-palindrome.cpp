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

#define MAXN 1005
char str[MAXN], str_2[MAXN];
int a, b;
int m[MAXN][MAXN];

int lcsub()
{
    for(int i = 0; i <= a ; ++i)
       m[i][0] = m[0][i] = 0;
    for(int i = 1; i <= a; ++i)
       for(int j = 1; j <= a; ++j)    
       {
           int val = (str[i - 1] == str_2[j - 1]) ? 1 : 0;
           m[i][j] = max(m[i - 1][j - 1] + val,
                     max(m[i - 1][j], m[i][j - 1]));
       }
    return m[a][a];
}

int main()
{
    int cas,i,j;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
        gets(str);
        a = strlen(str);
        memcpy(str_2, str, sizeof str);        
        reverse(str_2, str_2 + a);
        //printf("%s %s\n",str,str_2);
        printf("%d\n",lcsub());
    }
    return 0;
}
