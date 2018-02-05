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
#define M 55
char w[M];
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%s",w);       
         int i=0,x=0,y=0,z=0,f=0;
         while(w[i] && w[i]=='?')
            i++,x++;
         if(x<1 || !w[i] || !isalpha(w[i]) || w[i]!='M'){f=1;goto end;}
         //printf(":D");
         i++;
         while(w[i] && w[i]=='?')
            i++,y++;
         if(y<1 || !w[i] || !isalpha(w[i]) || w[i]!='E'){f=1;goto end;}
        // printf(":D");
         i++;
         while(w[i] && w[i]=='?')
            i++,z++;
         if(z<2 || w[i]){f=1;goto end;} 
         if(x+y!=z)f=1;        
         //printf(":D");
         end:
             if(f)printf("no-theorem\n");
             else printf("theorem\n");
    }
    return 0;
}
