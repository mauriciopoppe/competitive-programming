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
#define M 100001
int size[M],sum[M];
int main()
{
    //long start=clock();
    F(i,M)
      size[i]=sum[i]=1;
    for(int i=2;i<=M;++i)
        for(int j=i;j<=M;j+=i)
          ++size[j], sum[j]+=i;
    //printf("%ld\n",clock()-start);
    //F(i,10)printf("-%d-  %d[%d]\n",i,size[i],sum[i]);
    //SP;
    int cas,a,b,k;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d%d%d",&a,&b,&k);
         LL g=0, h=0;
         for(int i=a;i<=b;++i)
           if(i%k==0)
             //g+=(LL)size[i], h+=(LL)sum[i];
             g+=size[i], h+=sum[i];
         printf("%lld %lld\n",g,h);
    }
    
    return 0;
}
