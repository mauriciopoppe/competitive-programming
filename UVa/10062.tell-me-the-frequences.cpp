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

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
     if(a.second!=b.second)return a.second<b.second;
     return a.first>b.first;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string w;
    int cas=0;
    while(getline(cin,w))
    {
        if(cas)NL;
        cas=1;         
        map<int,int> m;
        TR(w,it)m[*it]++;
        vector<pair<int,int> > v(ALL(m));
        sort(ALL(v),cmp);
        TR(v,it)printf("%d %d\n",it->first,it->second);
    }
    return 0;
}
