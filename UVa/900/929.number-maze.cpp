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
#define M 1000
int a[M][M];
int main()
{
    int r,c,n;
    scanf("%d",&n);
    while(n--)
    {
         scanf("%d%d",&r,&c);
         F(i,r)
           F(j,c)
              scanf("%d",&a[i][j]);
         
         F(i,r)
           F(j,c)
              if(i-1>=0 && j-1>=0)a[i][j]+=min(a[i-1][j],a[i][j-1]);
              else if(i-1>=0)a[i][j]+=a[i-1][j];
              else if(j-1>=0)a[i][j]+=a[i][j-1];
         printf("%d\n",a[r-1][c-1]);
    }
    return 0;
}
