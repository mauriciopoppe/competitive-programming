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

int v[4];
bool b[10000005];

void sieve()
{
     for(int i = 4; i <= 10000000; i += 2)
        b[i] = 1;
     for(int i = 3; i * i <= 10000000; i += 2)
        if(!b[i])
           for(int j = i * i; j <= 10000000; j += 2 * i) 
              b[j] = 1;    
}

bool solve(int n)
{
     if(n < 8)
         return false;
     if(n & 1)
     {
         n -= 5;
         v[0] = 2;
         v[1] = 3;  
     }   
     else
     {
         n -= 4;
         v[0] = 2;
         v[1] = 2;    
     }
     
     if(!b[2] && !b[n - 2])
     {
        v[2] = 2;
        v[3] = n - 2;
        return true;      
     }
     
     for(int i = 3; 2 * i <= n; i += 2)
        if(!b[i] && !b[n - i])
        {
            v[2] = i;
            v[3] = n - i;
            return true;     
        }
     return false;
}

int main()
{
    sieve();
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(solve(n))
           printf("%d %d %d %d\n", v[0], v[1], v[2], v[3]);
        else
           puts("Impossible.");
    }
    return 0;
}
