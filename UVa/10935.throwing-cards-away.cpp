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
    int n;
    while(scanf("%d",&n) && n)
    {
         queue<int> q;
         for(int i=1;i<=n;i++)q.push(i);
         printf("Discarded cards:");
         int k=0;
         while(q.size()!=1)
         {
              if(k)printf(",");
              k=1;             
              printf(" %d",q.front());
              q.pop();
              q.push(q.front());
              q.pop();
         }
         NL;
         printf("Remaining card: %d\n",q.front());
    }
    return 0;
}
