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
int v[26];
char w[500];
int main()
{
    int cas;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
         memset(v,0,sizeof v);       
         gets(w);
         int i=0;
         for(;w[i];i++)
           if(isalpha(w[i]))
             v[tolower(w[i])-'a']++;
         int mx=0;
         F(j,26)
           if(v[j]>mx)mx=v[j];
         F(j,26)       
           if(v[j]==mx)putchar(j+'a');
         NL;
    }
    return 0;
}
