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
    int n,q,t,cas=1;
    vector<int>::iterator up;
    while(scanf("%d",&n) && n)
    {                         
         vector<int> v(n);
         F(i,n) 
            scanf("%d",&v[i]);
         set<int> st;
         
         F(i,n)
            for(int j=i+1;j<n;j++)
               st.insert(v[i]+v[j]);
         vector<int> w(st.begin(),st.end());
         int s=w.size();
         printf("Case %d:\n",cas++);
         scanf("%d",&q);         
         F(i,q)
         {
              scanf("%d",&t);
              int mx=IMAX,best=-1;              
              F(i,s)
                if(abs(w[i]-t)<mx)
                {
                     mx=abs(w[i]-t);
                     best=i;             
                }
              printf("Closest sum to %d is %d.\n",t,w[best]);
         }
    }
    return 0;
}
