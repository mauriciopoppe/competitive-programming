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
char w[65];
int len;
int f;

int is_slump(int i, int j)
{
    //printf("%d %d\n",i,j);
    if(i == j) 
        return 1 & f;
        
    if(i > j)
        return 1 & f;
    
    if(w[i] != 'D' && w[i] != 'E')
        return 0;
    
    int k = i + 1;
    while(k < j && w[k] == 'F')
       ++k;
    //printf("k = %d\n",k);
    f = 1;
    return is_slump(k, j);
}

int is_slimp(int i, int j)
{
    int diff = j - i;
    //printf("DIFF = %d\n",diff);
    if(diff < 1)
        return 0;
    
    if(diff == 1)
        return w[i] == 'A' && w[j] == 'H';
    
    if(w[i] == 'A' && w[i + 1] == 'B')
        return is_slimp(i + 2, j - 1) && w[j] == 'C';
    
    return w[i] == 'A' && is_slump(i + 1, j - 1) && w[j] == 'C';
}

int solve()
{    
    int start, end;
    len = strlen(w);
    int i;
    start = 0;
    f = 0;
    for(i = len - 1; i >= 0; --i)
       if(w[i] == 'C' || w[i] == 'H')
          break;
    end = i;
    //printf("%d\n",end);
    int a = is_slimp(start, end);
    int b = is_slump(end + 1, len - 2);
    //printf("%d %d\n",a,b);    
    return a && b && w[len - 1] == 'G';
}

int main()
{
    int cas;
    printf("SLURPYS OUTPUT\n");
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s",w);
        if(solve())
           printf("YES\n");
        else
           printf("NO\n");        
    }
    printf("END OF OUTPUT\n");
    return 0;
}
