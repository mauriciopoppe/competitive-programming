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

struct person{
       string name;
       int money;
       person(string new_name)
       {
           name = new_name;
           money = 0;           
       }
       bool operator<(const person &other)const
       {
           return money < other.money; 
       }
};

vector<person> v;
int n, t;

int test()
{
    F(i, n)
       if(v[i].money != 0)
          return true;
    return false;       
}

int main()
{
    string name;
    string from, to;
    int money;
    int cas = 1;
    while(scanf("%d%d", &n, &t) && n + t > 0)
    {
        int k = 0;
        map<string, int> m;
        v.clear();
        
        //get names
        F(i, n)
        {
            cin >> name;
            m[name] = k++;
            v.push_back(person(name));  
        }
        
        //transactions
        F(i, t)
        {
            cin >> from >> to >> money;
            v[m[from]].money -= money;
            v[m[to]].money += money;
        }
        printf("Case #%d\n", cas++);
        while(test())
        {
             sort(ALL(v));
             int mn = min(-v[0].money, v[n - 1].money);
             printf("%s %s %d\n", v[n - 1].name.c_str(), v[0].name.c_str(), mn);
             v[0].money += mn;
             v[n - 1].money -= mn;
        }
        NL;
    }
    return 0;
}
