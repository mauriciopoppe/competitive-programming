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
int N[1001];
char w[4000];
int main()
{
    int cas;
    int people;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d",&people);
         memset(N,0,people*4);
         gets(w);
         int mn = 1<<10;
         F(i,people)
         {
            gets(w);
            for(int j = 0; w[j]; ++j)
                if(isspace(w[j]))
                   ++N[i];
            mn = min(mn, N[i]);
         }
         int f = 0;
         F(i,people)
         {
           if(N[i] == mn)
           {
               if(f)printf(" ");
               f=1;
               printf("%d",i+1);    
           }            
         }
         NL;
    }
    return 0;
}
