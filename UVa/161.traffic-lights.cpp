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
#define M 18000
int m[M+1];
int v[M+1];
int main()
{
    while(1)
    {
        scanf("%d%d%d",&v[0],&v[1],&v[2]);
        if(v[0]==0 && v[1]==0 && v[2]==0)break;
        int n=2;
        if(v[2]!=0)
        {  
             n=3;      
             while(scanf("%d",&v[n]) && v[n++]);
        }

        memset(m,0,sizeof m);
        F(i,n)
        {
             int j=1;
             while(j<=M)
             {
                m[j]++;
                j+=2*v[i];
             }
             //printf("here");
        }

        int i=2;
        for(;i<=M;i++)
           if(m[i-1]==0 && m[i]==n)break;
        if(i<=M)printf("%02d:%02d:%02d\n",i/3600,(i%3600)/60,i%60);
        else printf("Signals fail to synchronise in 5 hours\n");
    }
    return 0;
}
