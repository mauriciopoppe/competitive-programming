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
#define M 1<<16
typedef long long LL;
bitset<M> b;
void gen()
{
     b[1]=0;
     for(int i=4;i<=M;i+=2)b[i]=1;
     for(int i=3;i*i<=M;i+=2)
        if(!b[i])
           for(int j=i*i;j<=M;j+=i)
             b[j]=1;
}

int main()
{
    gen();
    //F(i,10)printf("%d ",a[i]);
    int t;
    while(1)
    {
        cin>>t;
        if(!t)break;
        int f=0;
        for(int i=2;i<=t-i;i++)
           if(!b[i] && !b[t-i])f++;
        printf("%d\n",f);       
    }
    return 0;
}
