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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t, n;
    char w[5000];
    scanf("%d",&t);
    F(z,t)
    {
          scanf("%d",&n);
          int lost=n, f=0;
          map<int,int> m;          
          while(1)
          {
              sprintf(w,"%d",n);
              int s=strlen(w),temp=0;
              F(i,s)
                  temp+=(w[i]-'0')*(w[i]-'0');                
              if(temp==1){f=1;break;}
              if(m[temp])break;
              m[temp]=1;
              n=temp;
              //printf(" %d\n",n);
              //SP;
          }
          if(f)printf("Case #%d: %d is a Happy number.\n",z+1,lost);
          else printf("Case #%d: %d is an Unhappy number.\n",z+1,lost);
    }
    return 0;
}
