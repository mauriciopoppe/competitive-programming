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
    int start,a,b,c;
    while(scanf("%d%d%d%d",&start,&a,&b,&c))
    {
         if(a+b+c+start==0)break;
         int total=0;
         total+=720;
         if(start>a)total+=(start-a)*9;
         else total+=(start+40-a)*9;
         total+=360;
         if(b>a)total+=(b-a)*9;
         else total+=(b+40-a)*9;
         if(b>c)total+=(b-c)*9;
         else total+=(b+40-c)*9;
         printf("%d\n",total);
    }
    return 0;
}
