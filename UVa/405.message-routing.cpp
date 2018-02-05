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

struct mta{
       string v[5];
};

int string_equal(string &a, string &b)
{
    return a == "*" || b == "*" || a == b;           
}

int is_equal(mta &a, mta &b)
{
    for(int i = 1; i < 5; ++i)
       if(!string_equal(a.v[i], b.v[i]))
          return 0;
    return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n, routes, message;
    string name;
    mta MTA;
    int cas = 1;
    while(scanf("%d", &n) != EOF)
    {
       map<string, vector<mta> > route;
       for(int i = 0; i < n; ++i)
       {
          cin >> name >> routes;
          vector<mta> a_vector;
          for(int j = 0; j < routes; ++j)
          {
             for(int k = 0; k < 5; ++k)
                cin >> MTA.v[k];
             a_vector.push_back(MTA);
          }
          route[name] = a_vector;
       }
       printf("Scenario # %d\n", cas++);
       scanf("%d", &message);
       for(int i = 0; i < message; ++i)
       {
          map<string, int> visited;
          string last = "";
                    
          for(int j = 0; j < 5; ++j)
             cin >> MTA.v[j];
                       
          string dest = MTA.v[0];
          string new_dest;
          string res = "";
          while(1)
          {
             int f = 0;
             new_dest = "";
             visited[dest] = 1;
             TR(route[dest], it)
                if(is_equal(*it, MTA))
                {
                   new_dest = it->v[0];
                   break;               
                }
             
             //printf("[%s] [%s]\n", dest.c_str(), new_dest.c_str());
             if(new_dest == "") 
             {
                res = "unable to route at " + dest;
                break; 
             }
             else
             {
                if(visited[new_dest])
                {
                    if(dest == new_dest)
                       res = "delivered to " + dest;
                    else
                       res = "circular routing detected by " + new_dest;
                    break;
                }
                dest = new_dest;
             }
          }
          printf("%d -- %s\n", i + 1, res.c_str());
       }
       NL;
    }
    return 0;
}
