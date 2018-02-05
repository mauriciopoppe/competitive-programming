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
#define M 205
char a[M],b[M];
int sum[M+1],ans[M];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--)
    {
         memset(a,0,sizeof(a));
         memset(b,0,sizeof(b));     
         scanf("%s %s",a,b);
         int sa=strlen(a),sb=strlen(b);
         if(sa>sb)
         {
             F(i,sa)
               if(!isdigit(b[i]))
                  b[i]='0';  
         }   
         else
         {
             F(i,sb)
               if(!isdigit(a[i]))
                  a[i]='0'; 
         }
         
         int c=0,mx=max(sa,sb);
         F(i,mx)
         {
             //printf("  %d %d\n",a[i]-'0',b[i]-'0');   
             sum[i]=a[i]+b[i]-2*'0'+c;
             if(sum[i]>9)c=1,sum[i]-=10;
             else c=0;
         }
         if(c)sum[mx++]=c;
         
         //drop zeros
         while(mx-1>=0 && sum[mx-1]==0)mx--;
         
         int f=0;
         for(int i=0;i<mx;i++)
         {
             if(sum[i])printf("%d",sum[i]),f=1;
             else
             {
                 if(f)printf("0");
             }
         }
         NL;
    }
    return 0;
}
