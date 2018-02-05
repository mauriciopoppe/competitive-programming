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
#define M 1000005
int n_players, n_roll;
int pos[M];
int roll[M];
int tp[102];

void solve()
{
    int j = 0; 
    for(int i = 0; j < n_roll; i = (i + 1) % n_players, ++j)
    {
        if(pos[i] + roll[j] >= 100)
        {
           pos[i] = 100;
           return;
        }
        pos[i] += roll[j];
        if(tp[pos[i]])
           pos[i] = tp[pos[i]];
        if(pos[i] == 100)
           return;
    }
}

int main()
{
    int cas;
    int n_lad, from, to;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d%d", &n_players, &n_lad, &n_roll);        
        memset(tp, 0, sizeof tp);
        F(i, n_players)
           pos[i] = 1;
           
        F(i, n_lad)
        {
           scanf("%d%d", &from, &to);
           tp[from] = to;
        }
        
        F(i, n_roll)
           scanf("%d", &roll[i]);
        
        solve();
        F(i, n_players)
           printf("Position of player %d is %d.\n", i + 1, pos[i]);
    }
    return 0;
}
