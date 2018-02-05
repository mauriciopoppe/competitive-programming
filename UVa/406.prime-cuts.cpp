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
#define M 1010
typedef long long LL;

bitset<M> b;
int p[M];
void gen()
{
     for(int i=4;i<=M;i+=2)b[i]=1;
     for(int i=3;i*i<=M;i+=2)
        if(!b[i])
          for(int j=i*i;j<=M;j+=2*i)
            b[j]=1;
     int j=0;
     p[j++]=1;
     FOR(i,2,M)if(!b[i])p[j++]=i;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    gen();
    int n,c;
    while(cin>>n>>c)
    {       
         int j=0;
         while(p[j]<=n)j++;
         int m=j>>1,k=0;
         //printf("%d\n",j);
         int i=0;
         if(j&1)
         {
             k=c*2-1;
             i=m-(k>>1); 
             if(k>=j)k=j,i=0;
         }
         else
         {
             k=c*2;
             i=m-(k>>1);           
             if(k>=j)k=j,i=0;
         }
         //printf("%d %d %d\n",j,k,m);   
               
         printf("%d %d:",n,c);
             for(int j=0;j<k;i++,j++)printf(" %d",p[i]);    
         NL;NL;
    }    
    return 0;
}
