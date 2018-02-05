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
#define M 1000002
int m,b[M];
char w[M];
void kmp()
{
     int i=0,j=-1;
     b[i]=j;
     while(i<m)
     {
          while(j>=0 && w[i]!=w[j])j=b[j];
          ++i, ++j;
          b[i]=j;     
     }
     int over=m-b[m];
     if((m%over)==0)printf("%d\n",m/over);
     else printf("1\n");
}

int main()
{
    while(gets(w) && strcmp(w,"."))
         m=strlen(w), kmp();
    return 0;
}
