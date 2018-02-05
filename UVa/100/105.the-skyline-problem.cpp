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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
int sky[10002];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    memset(sky,0,sizeof(sky));
    int l,r,h;
    while(cin>>l>>h>>r)
        FOR(i,l,r)sky[i]=max(sky[i],h);
        
    int f=0;
    for(int i=1;i<=10000;++i)
    {            
        if(sky[i]!=sky[i-1])
        {
           if(f)printf(" ");
           printf("%d %d",i,sky[i]);
           f=1;
        }
    }      
    NL;
    return 0;
}
