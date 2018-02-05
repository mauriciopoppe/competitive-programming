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
#define max3(a,b,c) (max(max(a,b),max(b,c)))
typedef long long LL;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char a[35],b[35],r[10000],w[10000];
    while(gets(w))
    {
          sscanf(w,"%s%s",a,b);  
          int sa=strlen(a);
          int sb=strlen(b);
          if(!strcmp(a,"0") && !strcmp(b,"0"))break;
          
          LL x=0,y=0;
          for(int i=sa-1,j=0;i>=0;i--,j++)
             if(a[i]=='1')
               x+=1<<j;
          
          for(int i=sb-1,j=0;i>=0;i--,j++)
             if(b[i]=='1')
               y+=1<<j;
          
          int j=0;
          LL z=x*y;
          //printf("%lld %lld %lld\n",x,y,z);
          
          if(z)
              while(z)
              {
                  r[j++]=(z%2)+'0';
                  z>>=1;
              }
          else
          {
              r[j++]='0';          
              for(int k=max(sa,sb);j<k;)
                r[j++]=' ';
          }
          r[j]='\0';
          
          int mx=max3(sa,sb,j);
          reverse(r,r+mx);
          
          string line=string(max(sa,sb),'-');
          string zeros=string(sa,'0');
          
          printf("%*s\n%*s\n%*s\n",mx,a,mx,b,mx,line.c_str());
          reverse(b,b+sb);
          F(i,sb)
          {
              if(b[i]=='0')printf("%*s",mx-i,zeros.c_str());
              else printf("%*s",mx-i,a);
              //F(k,i)putchar(' ');              
              putchar(10);
          }
          string end=string(mx,'-');
          printf("%s\n%s\n\n",end.c_str(),r);
    }
    return 0;
}
