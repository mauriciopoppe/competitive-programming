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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,m,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         vector<vector<int> > v;
         map<int,int> mp;
         map<int,int> size;
         v.resize(1);
         int ind=1;                                   
         FOR(i,1,n+1)
         {
             scanf("%d",&k);
             if(mp[k])
                  v[mp[k]].push_back(i);
             else
             {
                  vector<int> t;
                  t.push_back(i);
                  v.push_back(t);
                  mp[k]=ind++;
             }
         }
         
         TR(mp,it)
              size[it->first]=v[it->second].size();   
         stringstream ss;
         F(i,m)
         {
              scanf("%d%d",&k,&n);
              if(!mp[n] || size[n]<k)ss<<"0\n";
              else ss<<v[mp[n]][k-1]<<"\n";
         }         
         printf("%s",ss.str().c_str());
    }
    return 0;
}
