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
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

bool cmp(const pair<char,int> &a,const pair<char,int> &b)
{
    if(b.second!=a.second)return a.second>b.second;
    return a.first<b.first; 
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    map<char,int> m;
    int t;
    cin>>t;
    char c;
    while((c=getchar())!=EOF)
    {
          if(isalpha(c))
               m[toupper(c)]++;
    }
    vector<pair<char,int> > v(ALL(m));
    sort(v.begin(),v.end(),cmp);    
    TR(v,it) printf("%c %d\n",it->first,it->second);
    return 0;
}
