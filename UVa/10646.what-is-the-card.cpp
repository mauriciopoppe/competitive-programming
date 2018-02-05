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
    scanf("%d", &cas);
    F(z, cas)
    {
         deque<string> pile(27), hand(25);
         for(int i = 0; i < 27; ++i)
            cin >> pile[i];
         for(int i = 0; i < 25; ++i)
            cin >> hand[i];
         int y = 0;
         for(int i = 0; i < 3; ++i)
         {
             string card = pile.back();
             int val = 10;
             if(isdigit(card[0]))
                val = card[0] - '0';
             pile.pop_back();
             y += val;
             int number = 10 - val;
             for(int j = 0; j < number; ++j)
                pile.pop_back();
         }
         while(!hand.empty())
         {
              pile.push_back(hand.front());
              hand.pop_front();               
         }
         printf("Case %d: %s\n", z + 1, pile[y - 1].c_str());
    }
    return 0;
}
