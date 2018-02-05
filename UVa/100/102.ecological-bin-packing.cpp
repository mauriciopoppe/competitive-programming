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

char w[][4]={"BCG","BGC","CBG","CGB","GBC","GCB"};
int t[6],a[9];
bitset<10> b;

int main()
{   
    map<char,int> m;
    m['B']=0;
    m['G']=1;
    m['C']=2;
    while(cin>>a[0])
    {
         int mn=2147483647,ind=0;    
         memset(t,0,sizeof(t));       
         FOR(i,1,9)cin>>a[i];
         F(i,6)
         {
              b.reset(); 
              F(j,3)
                 b[j*3+m[w[i][j]]]=1;
              F(j,9)
                 if(!b[j])t[i]+=a[j];         
              if(t[i]<mn)mn=t[i],ind=i;
         }
         printf("%s %d\n",w[ind],t[ind]);
    }
    return 0;
}
