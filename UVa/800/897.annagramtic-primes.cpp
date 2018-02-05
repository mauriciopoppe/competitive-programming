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

int main()
{
    int t[]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
    int l=sizeof(t)/4;
    int n;
    while(scanf("%d",&n) && n)
    {
         int k=1;
         while(k<=n)k*=10;
         int i=0;
         for(i=0;i<l;i++)
              if(t[i]>n && t[i]<k)
                break;
         if(i==l)printf("0\n");
         else printf("%d\n",t[i]);
         
    }
    return 0;
}
