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

char w[32][33];

int main()
{
    char c,q='X';
    int cas,x,y;
    scanf("%d",&cas);
    F(i,32)
       w[i][32]='\0';
    F(z,cas)
    {
         scanf("%d%d",&x,&y);   
         getchar();   
         memset(w,'.',sizeof w);
         F(i,32)
            w[i][32]='\0';
         /*for(int i=31;i>=0;i--)
            printf("%s\n",w[i]);
         SP;*/
         while((c=getchar()) && c!='.')
         {
               if(c=='E')w[y-1][x++]=q;
               else if(c=='N')w[y++][x]=q;
               else if(c=='W')w[y][(x--)-1]=q;
               else w[(y--)-1][x-1]=q;
         }
         printf("Bitmap #%d\n",z+1);
         for(int i=31;i>=0;i--)
            printf("%s\n",w[i]);
         NL;
    }
    return 0;
}
