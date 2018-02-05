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
#define M 46350
#define T 1000000
bitset<M+1> b;
int p[M],k=0;
int v[T];
void gen()
{
     for(int i=4;i<M;i+=2)b[i]=1;
     for(int i=3;i*i<M;i+=2)
       if(!b[i])
         for(int j=i*i;j<M;j+=2*i)
           b[j]=1;
     p[k++]=2;
     for(int i=3;i<M;i+=2)
        if(!b[i])p[k++]=i;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    gen();
    //F(i,20)printf("%d ",p[i]);NL;
    int a,b,ca,cb,fa,fb;    
    while(scanf("%d%d",&a,&b)!=EOF)
    {
         int t=0;
         if(a==1 || a==2)v[t++]=2,a=3;  
         if(!(a%2))++a;                   
         for(unsigned int i=a;i<=b;i+=2)
         {
              bool f=0;   
              for(int j=1;j<k && p[j]*p[j]<=i;j++)
              //{   printf("%d %d\n",i,p[j]);
                 if(i%p[j]==0){f=1;break;}
                 //}
              if(!f)v[t++]=i;
         }
         
         //F(i,t)printf("%d ",v[i]);NL;
         
         if(t<2)printf("There are no adjacent primes.\n");
         else
         {
             ca=cb=fa=fb=0;
             int mn=999999,mx=0;
             FOR(i,1,t)
             {
                 int x=v[i]-v[i-1];      
                 if(x<mn)mn=x,ca=v[i-1],cb=v[i];
                 if(x>mx)mx=x,fa=v[i-1],fb=v[i];
             }
             printf("%d,%d are closest, %d,%d are most distant.\n",ca,cb,fa,fb);
         }
             
         
    }
    return 0;
}
