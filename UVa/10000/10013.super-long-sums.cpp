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
int a[M],b[M];
char sum[M];

int main()
{
    int t,n;
    char temp[5];
    scanf("%d",&t);
    F(q,t)
    {
          if(q)printf("\n");
          scanf("%d",&n);
          getchar();
          F(i,n)
          {
              gets(temp);
              a[i]=temp[0]-'0';
              b[i]=temp[2]-'0';  
          }
          int j=0;
          int c=0,x;
          for(int i=n-1;i>=0;i--)
          {
              //printf("%d %d\n",a[i],b[i]);    
              x=a[i]+b[i]+c;
              if(x>9)x-=10,c=1;
              else c=0;
              sum[i]=x+'0';
          }
          //reverse(sum,sum+n);
          sum[n]='\0';
          printf("%s\n",sum);
    }
    return 0;
}
