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
    int n,k;
    while(scanf("%d",&n) && n)
    {
         LL s=0;
         priority_queue<int,vector<int>, greater<int> > q;
         F(i,n)scanf("%d",&k), q.push(k);
         
         while(q.size()>1)
         {
              int a=q.top();
              q.pop();
              int b=q.top();
              q.pop();
              //printf("%d %d\n",a,b);
              int t=a+b;
              q.push(t);
              s+=t;         
         }
         
         printf("%lld\n",s);
    }
    return 0;
}
