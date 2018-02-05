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
int cnt[130];
int cnt_b[130];
char a[100000], b[100000];
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    int cas;
    scanf("%d",&cas);
    gets(a);
    while(cas--)
    {
        gets(a);        
        
        gets(a);        
        gets(b);
        
        map<int,char> m_a;
        map<int,char> m_b;

        map<char,char> encode;
        memset(cnt,0,sizeof cnt);
        memset(cnt_b,0,sizeof cnt_b);
        
        for(int i = 0; a[i]; ++i)
           ++cnt[a[i]];
        
        for(int i = 0; b[i]; ++i)
           ++cnt_b[b[i]];
        
        for(int i = 'A'; i <= 'z'; ++i)
        {
           if(cnt[i])
              m_a[cnt[i]] = (char)(i);
           if(cnt_b[i])
              m_b[cnt_b[i]] = (char)(i);
        }
        typeof(m_a.rbegin()) it = m_a.rbegin();
        typeof(m_b.rbegin()) it2 = m_b.rbegin();
        for(;it != m_a.rend(); ++it, ++it2)
           encode[it2->second] = it->second;
        
        for(int i = 0; b[i]; ++i)
           printf("%c",encode[b[i]]);
           NL;
        if(cas)
          NL;
    }
    return 0;
}
