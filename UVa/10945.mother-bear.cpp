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
char w[1000000];
char z[1000000];

int solve(int size)
{
    for(int i = 0, j = size - 1; i < j; ++i, --j)
       if(z[i] != z[j])
          return 0;
    return 1;    
}

int main()
{
    while(gets(w) && strcmp(w, "DONE"))
    {
        int size = 0;
        for(int i = 0; w[i]; ++i)
           if(isalpha(w[i]))
               z[size++] = tolower(w[i]);
        
        if(solve(size))
           puts("You won't be eaten!");
        else
           puts("Uh oh..");         
    }
    return 0;
}
