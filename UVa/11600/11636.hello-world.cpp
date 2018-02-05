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
#define M 10001
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,cas=0;
    while(scanf("%d",&t))           
    {
         if(t<0)break;
         printf("%d,",(int)ceil(log(t)/log(2))); 
         ++cas;
         if(cas%30==0)printf("\n");
    }
    return 0;
}
