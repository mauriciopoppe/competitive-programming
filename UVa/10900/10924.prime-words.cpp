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
#define M 1050
bitset<M+1> b;

void gen()
{
     for(int i=4;i<M;i+=2)b[i]=1;
     for(int i=3;i*i<=M;i+=2)
       if(!b[i])
         for(int j=i*i;j<=M;j+=2*i)
           b[j]=1;
     b[0]=1;  
}

int main()
{
    gen();
    //F(i,100)if(!b[i])printf("%d ",i);
    char w[100];
    while(gets(w))
    {
         int c=0,s=strlen(w);
         F(i,s)
         {
             if(islower(w[i]))c+=w[i]-'a'+1;
             else c+=w[i]-'A'+27; 
             //printf("%d\n",c);             
         }
         if(!b[c])printf("It is a prime word.\n");
         else printf("It is not a prime word.\n");
    }
    
    return 0;
}
