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
#define M 1000001
bitset<M> b;

int sum(int i)
{
    int r=0;
    while(i)
    {
        r+=i%10;
        i/=10;    
    }
    return r;
}
int main()
{
    for(int i=1;i<M;i++)
    {
        int t=i+sum(i);
        if(t<M)b[t]=1;
    }
    for(int i=1;i<M;i++)
         if(!b[i])
            printf("%d\n",i);
    //SP;
    return 0;
}
