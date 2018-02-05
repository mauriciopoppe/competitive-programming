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
int n[5843];

int main()
{
    int c2,c3,c5,c7;
    int t2=0,t3=0,t5=0,t7=0;
    n[0]=1;
    for(int i=1;i<5843;i++)
    {
         int next=n[i-1]+1;
         while((c2=2*n[t2])<next)t2++;
         while((c3=3*n[t3])<next)t3++;
         while((c5=5*n[t5])<next)t5++;
         while((c7=7*n[t7])<next)t7++;
         n[i]=min(min(c2,c3),min(c5,c7));
    }
    
    //printf("here");
    int t;
    while(cin>>t && t)
    {
         int k=t%10,x=t%100;
         string r="th";
         if(x!=11 && x!=12 && x!=13)
         {
             if(k==1)r="st";
             else if(k==2)r="nd";
             else if(k==3)r="rd";
         }
         printf("The %d%s humble number is %d.\n",t,r.c_str(),n[t-1]);
    }
    return 0;
}
