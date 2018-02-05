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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
map<char,int> m,res;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string a,b;
    while(getline(cin,a) && getline(cin,b))
    {
          m.clear();
          res.clear();          
          TR(a,it)m[*it]++;
          TR(b,it)
          {
               if(m[*it])
               {
                   res[*it]++;
                   m[*it]--;
               }   
          }
          
          TR(res,it)
          {
              F(i,it->second)putchar(it->first);       
          }
          NL;
    }
    return 0;
}
