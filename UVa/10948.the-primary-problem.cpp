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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 1000000
bitset<M+1> b;
void gen()
{
     for(int i=4;i<=M;i+=2)b[i]=1;
     for(int i=3;i*i<=M;i+=2) 
        if(!b[i])
        for(int j=i*i;j<=M;j+=2*i)
           b[j]=1;     
}
int main()
{
    gen();
    int n;
    while(cin>>n && n)
    {
         int i=2,f=0;        
         for(;i+i<=n;i++)
            if(!b[i] && !b[n-i]){f=1;break;}
         
         printf("%d:\n",n);
         if(!f)printf("NO WAY!\n");
         else printf("%d+%d\n",i,n-i);
            
    }
    return 0;
}
