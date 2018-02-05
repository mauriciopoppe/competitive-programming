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
char w[257];
int main()
{
    while(gets(w))
    {
        int c = 0;
        int s = strlen(w);
        for(int i = s - 1; i >= 0; --i)          
        {
             if(w[i] >= 'p' && w[i] <= 'z')
                 ++c;
             else if(w[i] == 'C' || w[i] == 'E' || w[i] == 'D' || w[i] == 'I') 
             {
                 if(c >= 2)
                    --c;
                 else
                 {
                    c = 0;
                    break;
                 }
             }
             else
             {
                 if(c == 0)
                     break;
             }

        }
         if(c == 1)
            printf("YES\n");
         else
            printf("NO\n");
    }
    return 0;
}
