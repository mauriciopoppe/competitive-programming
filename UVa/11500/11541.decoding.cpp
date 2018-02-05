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
char w[201];
char number[201];
int main()
{
    int cas;
    int n;
    char alpha;
    char c;
    scanf("%d",&cas);
    getchar();
    F(z,cas)
    {
        printf("Case %d: ",z+1);    
        n = 0;
        while((c = getchar()) != '\n')
        {
            if(isalpha(c))
            {
               if(n)
               {
                   int digits = 0; 
                   F(i,n)
                     digits = digits * 10 + number[i]-'0';
                   F(i,digits)
                      putchar(alpha);
                   n = 0;
               }
               alpha = c;
            }
            else
               number[n++] = c;     
        }
       if(n)
       {
           int digits = 0; 
           F(i,n)
             digits = digits * 10 + number[i]-'0';
           F(i,digits)
              putchar(alpha);
           n = 0;
       }
       NL;
    }
    return 0;
}
