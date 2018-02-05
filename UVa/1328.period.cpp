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
#define M 1000001
int b[M+1],m;
char w[M+1];
int main()
{
    int cas;
    char c;
    scanf("%d",&cas);
    F(z,cas)
    {
          scanf("%d %s",&m,w);
          //kmp
          int i=0,j=-1;
          b[i]=j;
          printf("Test case #%d\n",z+1);
          while(i<m)
          {
               while(j>=0 && w[i]!=w[j])j=b[j];
               ++i,++j;
               b[i]=j;
               int x=i-b[i];
               if((i%x)==0 && i/x>1)
                  printf("%d %d\n",i,i/x);
          }
          NL;
    }
    return 0;
}
