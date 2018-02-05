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

bool fully_grown(int i, int j);
bool mutagenic(int i, int j);

char w[5000];

bool simple(int i)
{
    return w[i] == 'A'; 
}

bool fully_grown(int i, int j)
{    
    if(j - i >= 2 && w[j - 1] == 'A' && w[j] == 'B')
    {
         //printf("%d %d\n",i,j);SP;
         if(j - i == 2)
            return simple(i);
         else
            return fully_grown(i, j - 2) || mutagenic(i, j - 2);
    }
    return 0;
}

bool mutagenic(int i, int j)
{
    //printf("%d %d\n",i,j);SP; 
    if(j - i >= 2 && w[i] == 'B' && w[j] == 'A')
    {
         if(j - i == 2)
            return simple(i + 1);
         else
            return fully_grown(i + 1, j - 1) || mutagenic(i + 1, j - 1);
    }
    return 0;
}

int solve()
{
    int len = strlen(w);
    if(!(len & 1))    
      return 0;
    if(len == 1 && simple(0))
      return 1;
    if(fully_grown(0, len - 1))
      return 2;
    if(mutagenic(0, len - 1))
      return 3;
    return 0;
}

int main()
{
    int cas;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
        gets(w);   
        int k = solve();
        if(k == 1)printf("SIMPLE\n");
        else if(k == 2)printf("FULLY-GROWN\n");
        else if(k == 3)printf("MUTAGENIC\n");
        else printf("MUTANT\n");
    }
    return 0;
}
