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
    int n,d;
    while(cin>>n>>d)
    {
         int i=0;
         printf("[");
         while(1)
         {
            int t=n/d;
            n-=t*d;
            swap(n,d);
            printf("%d",t);
            if(!d)break;            
            if(!i)printf(";");
            else printf(",");
            ++i; 
         }          
         printf("]\n"); 
    }
    return 0;
}
