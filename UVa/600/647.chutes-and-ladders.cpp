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
#define M 101
int tp[M];
int miss[M], extra[M];
int roll[1001], can_play[M];
int player[M];
char w[500];

void play(int n)
{     
    for(int i = 0, dice = 0; ; i = (i + 1) % n, ++dice)
    {
        if(!can_play[i])
        {
           can_play[i] = 1;
           continue;
        }
        
        //check win
        if(player[i] + roll[dice] > 100)
           continue;
        
        if(player[i] + roll[dice] == 100)
        {
            printf("%d\n", i + 1);
            return;         
        }
        
        //advance
        player[i] += roll[dice];        
    
        //check ladder or chute
        if(tp[player[i]])
           player[i] = tp[player[i]];
        
        //check miss or extra
        if(extra[player[i]])
            i = (i - 1 + n) % n;
        else if(miss[player[i]])
            can_play[i] = 0;
    }    
}

int main()
{
    gets(w);
    for(int i = 0; w[i] != '0'; i += 2) 
       roll[i >> 1] = w[i] - '0';
    
    int n_players;
    int from, to;
    while(scanf("%d", &n_players) && n_players)
    {
        memset(tp, 0, sizeof tp);
        memset(extra, 0, sizeof extra);
        memset(miss, 0, sizeof miss);
        memset(can_play, 1, sizeof can_play);
        memset(player, 0, sizeof player);
        
        while(scanf("%d%d", &from, &to) && from + to != 0)
           tp[from] = to;
        
        while(scanf("%d", &to) && to)
           if(to > 0)
              extra[to] = 1;
           else
              miss[-to] = 1;
        
        play(n_players);
    }
    return 0;
}
