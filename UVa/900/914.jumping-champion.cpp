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
#define M 1000001
bitset<M> b;
int p[M];
int main()
{
    for(int i=4;i<M;i+=2)b[i]=1;
    for(int i=3;i*i<M;i+=2)
       if(!b[i])
         for(int j=i*i;j<M;j+=2*i)
           b[j]=1;
    
    int j=0;
    p[j++]=2;
    for(int i=3;i<M;i+=2)
       if(!b[i])p[j++]=i;
    
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
          int mx=0,c=1,best=-1;
          map<int,int> m;
          scanf("%d %d",&a,&b);
          
          int s=0;
          while(s<j && p[s]<a)++s;
          ++s;
          while(s<j && p[s]<=b)
            //printf("%d %d\n",p[s],p[s-1]),SP,
            m[p[s]-p[s-1]]++,++s;
            
          //TR(m,it)printf("xx %d %d\n",it->first,it->second);
            
          TR(m,it)
          {
               if(it->second>mx)mx=it->second,best=it->first,c=0;
               else if(it->second==mx)c=1;
          }
          
          if(c)printf("No jumping champion\n");
          else printf("The jumping champion is %d\n",best);
    }
    return 0;
}
