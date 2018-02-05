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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 1000001
char sum[M];
char temp[M][4];
int t,n,c,x,i,q;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
          scanf("%d",&n);
          getchar();
          for(i=0;i<n;++i)
              gets(temp[i]);
          c=0;
          for(i=n-1;i>=0;--i)
          {
              sum[i]=temp[i][0]+temp[i][2]+c-48;
              if(sum[i]>57)sum[i]-=10,c=1;
              else c=0;
          }
          sum[n]='\0';
          printf("%s",sum);
          //printf("%d\n",t);
          putchar(10);
          if(t)putchar(10);
    }
    return 0;
}
