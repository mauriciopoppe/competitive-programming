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

int main()
{
    char w[100];
    int n;
    while(scanf("%d",&n) && n)
    {
          //get max digit
          int mx=1;
          sprintf(w,"%d",n);
          int s=strlen(w);
          F(i,s)
             if(w[i]-'0'>mx)mx=w[i]-'0';
          
          //convert number
          int i=mx+1;
          for(;i<101;i++)
          {
               int t=0,k=1;          
               for(int j=s-1;j>=0;j--)
                 t+=(w[j]-'0')*k,k*=i;
               //printf("%d %d\n",i,t);               
               if(sqrt(t)-(int)sqrt(t)==0)break;               
          }
          printf("%d\n",i);
          
    }
    return 0;     
}
