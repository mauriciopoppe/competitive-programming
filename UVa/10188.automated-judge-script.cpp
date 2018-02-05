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

char answer[101][150], team[101][150];
int nans, nteam;

char a[15000], b[15000];

void solve()
{
    int k = 0;
    int mn = min(nans, nteam);
    for(k = 0; k < mn; ++k)
       if(strcmp(answer[k], team[k]))
          break;
    if(k == mn && nans == nteam)
    {
       puts("Accepted");
       return;  
    }
    
    int size_a = 0, size_b = 0;
    for(int i = 0; i < nans; ++i)
       for(int j = 0; answer[i][j]; ++j)
          if(isdigit(answer[i][j]))
             a[size_a++] = answer[i][j];
    a[size_a] = '\0';

    for(int i = 0; i < nteam; ++i)
       for(int j = 0; team[i][j]; ++j)
          if(isdigit(team[i][j]))
             b[size_b++] = team[i][j];
    b[size_b] = '\0';
    if(size_a == size_b && !strcmp(a, b))
       puts("Presentation Error");
    else
       puts("Wrong Answer");
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas = 1;
    while(scanf("%d", &nans) && nans)
    {
        gets(answer[0]);
        for(int i = 0; i < nans; ++i)
           gets(answer[i]);
        scanf("%d", &nteam);
        gets(team[0]);
        for(int i = 0; i < nteam; ++i)
           gets(team[i]);
        printf("Run #%d: ", cas++);
        solve();
        
    }
    return 0;
}
