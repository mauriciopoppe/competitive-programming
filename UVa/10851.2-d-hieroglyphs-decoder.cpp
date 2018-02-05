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
char m[10][85];
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
         gets(m[0]);
         F(i,10)
            gets(m[i]);
         
         int len = strlen(m[0]);
         for(int i = 1; i < len - 1; ++i)
         {
            int p = 0;     
            for(int j = 8; j >= 1; --j)
            {
               p = p * 2;     
               if(m[j][i] == '\\')
                  ++p;
            }
            putchar(p);  
         }   
         NL;
    }
    return 0;
}
