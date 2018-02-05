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
#define M 100002
char a[M],b[M],m;
int t[M];
int kmp()
{
     int i=0,j=-1;
     t[i]=j;
     while(i<m)
     {
          while(j>=0 && b[i]!=b[j])j=t[j];
          ++i,++j;
          t[i]=j;     
     }
         F(i,m+1)printf("%d ",t[i]);NL;
     i=0,j=0;
     while(i<m)
     {
          while(j>=0 && a[i]!=b[j])j=t[j];     
          ++i,++j;
     }
     return j;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(gets(a))
    {
         m=strlen(a);
         for(int i=m-1,j=0;i>=0;--i,++j)
            b[j]=a[i];        
         int j=m-kmp()-1;
         printf("%d\n",j);
         printf("%s",a);
         for(;j>=0;--j)
           putchar(a[j]);
           //printf("]");
         NL;
    }
    return 0;
}
