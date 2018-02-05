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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    string w;
    while(1)
    {
            
          int down=0,up=10;  
          while(scanf("%d",&n) && n)
          {
               getchar();
               getline(cin,w);
               if(w=="too high")up=min(up,n-1);
               else if(w=="too low")down=max(down,n+1);
               else
               {
                    if(n>=down && n<=up)printf("Stan may be honest\n");
                    else printf("Stan is dishonest\n");
                    break;
               }                                 
          }
          if(!n)break;
    }
    return 0;
}
