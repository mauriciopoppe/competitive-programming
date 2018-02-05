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

struct task{
       int id, cost, ini;
       bool operator<(const task &other)const
       {
           if(cost != other.cost)
              return other.cost < cost;
           return other.id < id; 
       }
} t;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char w[50];
    int id, cost, k;
    priority_queue<task> q;
    while(gets(w) && w[0] != '#')
    {
        sscanf(w, "%*s%d%d", &t.id, &t.cost);
        t.ini = t.cost;
        q.push(t);
    }
    scanf("%d", &k);
    for(int i = 0; i < k; ++i)
    {
        t = q.top();    
        q.pop();
        printf("%d\n", t.id);
        t.cost = t.cost + t.ini;
        q.push(t);
    }
    //SP;
    return 0;
}
