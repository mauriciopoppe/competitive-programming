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
char w[10000];

bool isvowel(char w)
{
     w=tolower(w);
     if(w=='a' || w=='e' || w=='i' || w=='o' || w=='u')return 1;
     return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char c;
    int j=0,f=0;
    while((c=getchar())!=EOF)
    {
         if(isalpha(c))                    
         {
             if(!j)
             {
                 if(isvowel(c))f=1;
                 else f=0;
             }                              
             w[j++]=c;
         }
         else
         {
             if(j)
             {
                 string t=string(w,w+j);                      
                 if(!f)
                 {
                     t+=t[0];
                     t.erase(0,1);
                 }
                 t+="ay"; 
                 printf("%s",t.c_str());
                 j=f=0;
             }
             putchar(c);
         }
    }
    return 0;
}
