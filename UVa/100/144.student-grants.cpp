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

struct student{
       int ind, money;
};

int main()
{
    int st, k;
    while(scanf("%d%d", &st, &k) && st + k != 0)
    {
         student s = {0, 0};
         queue<student> q;
         for(int i = 0; i < st; ++i)
         {
             s.ind = i + 1, s.money = 0;
             q.push(s);
         }
         int money = 1;
         int store = 1;
         while(!q.empty())
         {
              student t = q.front();
              q.pop();
              if(t.money + store < 40)
              {
                  t.money += store;
                  q.push(t);
                  store = 0;
              }
              else
              {
                  printf("%3d", t.ind);
                  store = t.money + store - 40;
              }
              if(store == 0)
              {
                  money++;
                  if(money > k) money = 1;     
                  store = money;
              }
         }
         NL;
    }
    return 0;
}
