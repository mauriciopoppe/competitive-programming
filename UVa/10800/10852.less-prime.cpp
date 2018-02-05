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
#define M 10001
bitset<M+1> b;
void gen()
{
     b[0]=b[1]=1;
     for(int i=4;i<=M;i+=2)b[i]=1;
     for(int i=3;i*i<=M;i+=2) 
        if(!b[i])
        for(int j=i*i;j<=M;j+=2*i)
           b[j]=1;     
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    gen();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int k=n/2+1;
        int i=k;
        for(;i<=n;i++)if(!b[i])break;
        printf("%d\n",i);
    }
    return 0;
}
