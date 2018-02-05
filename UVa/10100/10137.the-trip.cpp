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
    int c;
    double v[1001];
    while(cin>>c && c)
    {
         double sum=0,pos=0,neg=0;        
         F(i,c)scanf("%lf",&v[i]),sum+=v[i];
         sum/=c;
         //printf("%lf\n",sum);
         F(i,c)
         {
           if(v[i]>sum)pos+=(double)((int)((v[i]-sum)*100)/100.0);
           else neg+=(double)((int)((sum-v[i])*100)/100.0);
           //printf("  %lf %lf\n",pos,neg);
         }
         
         if(neg>pos)printf("$%.2lf\n",neg);
         else printf("$%.2lf\n",pos);        
    }
    return 0;
}
