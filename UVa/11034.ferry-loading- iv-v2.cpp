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
#define M 1000000
int izq[M],der[M];
char w[10];
int main()
{
    int t;
    int len,n,k;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d%d",&len,&n);
         len*=100;
         int na=0,nb=0;
         F(i,n)
         {
               scanf("%d%s",&k,w);
               if(w[0]=='l') izq[na++]=k;
               else der[nb++]=k;
         }
         
         int a=0,ca=0,cb=0;
         F(i,na)
              if((a+=izq[i])>len)
                  a=izq[i],ca+=2;
         if(a)ca++;
         
         a=0;
         F(i,nb)
              if((a+=der[i])>len)
                  a=der[i],cb+=2;
         
         if(a)cb++;
         if(nb)++cb;
         printf("%d\n",max(ca,cb));
    }
    return 0;
}
