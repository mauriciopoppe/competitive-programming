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
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
#define NL printf("\n");
typedef long long LL;

int ans[151];
bitset<151> b;

void next(int &j, int &x)
{
    ++j;
    if(j==x+1)j=1;
}

int f(int x)
{
    for(int i=1;;i++)
    {
       int j=1;
       b.reset();
       F(k,x+1)b[k]=1;
       b[0]=0;
       b[1]=0;
       while(b[2])
       {
           int c=0;
           while(1)
           {
               next(j,x);
               if(b[j])
               {
                   ++c;
                   if(c==i)
                   {
                        //printf("%d\n",j);   
                        b[j]=0;
                        break;
                   }
               }
           }       
       }
       /*
       for(int q=0;q<5;q++)
         if(b[q])printf("%d ",q);
         NL;
       system("pause");
       //printf("%d\n",i);*/
       if(b.count()==0)return i;
    }
}

int main()
{
    //FOR(w,3,151)ans[w]=f(w);
    int t;
    while(cin>>t && t)
    {
       if(ans[t])printf("%d\n",ans[t]);
       else printf("%d\n",ans[t]=f(t));
    }    
    return 0;
}
