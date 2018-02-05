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
int v[100000];
int main()
{
    int n, k, last;
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; ++i)              
           scanf("%d", &v[i]);
        int peaks = n > 2 ? 0 : n;
        if(n > 2)
        {
            int f = v[n - 1] < v[0];
            for(int i = 1; i < n; ++i)
               if(f)
               {
                   peaks += v[i - 1] > v[i];
                   f = v[i - 1] < v[i]; 
               }
               else
               {
                   peaks += v[i - 1] < v[i];
                   f = v[i - 1] < v[i]; 
               }
           if(f)
               peaks += v[n - 1] > v[0];
           else
               peaks += v[n - 1] < v[0];
        }
        printf("%d\n", peaks);
    }
    return 0;
}
