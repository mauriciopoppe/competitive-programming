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
#define M 67000
int a[M],bitCount[M],n,row;
int r[16];
bool b[M];

void ini()
{
     int k=1<<16;
     F(i,k)
     {
         int c=0,j=i;
         for(c=0;j;c++)
            j&=j-1;
         bitCount[i]=c;  
     }
}

int getN()
{
    int c=0;
    for(int i=0;i<n;i++)
        c+=r[i]<<(n-i-1);
    return c;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    ini();
    
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d%d",&n,&row);
         getchar();
         F(i,row)
         {
            F(j,n)
               scanf("%d",&r[j]);
            a[i]=getN();
         }
         
         int mx=(1<<n);
         int best=16;
         F(i,mx)
         {
             memset(b,0,mx);
             int j=0; 
             for(;j<row;j++)
             {
                   int x=a[j]&i;
                   if(b[x])break;
                   b[x]=1;
             }
             if(j==row && bitCount[i]<best)best=bitCount[i];              
         }
         printf("%d\n",best);
    }
    return 0;
}
