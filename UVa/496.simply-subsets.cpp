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

int main()
{   
    string a,b,buf;
    while(getline(cin,a) && getline(cin,b))
    {
         int ca=0,cb=0;
         set<string> seta,setb,tot;
         
         stringstream sa(a);
         while(sa>>buf) seta.insert(buf);
         ca=seta.size();
         
         stringstream sb(b);
         while(sb>>buf) setb.insert(buf);
         cb=setb.size();
         
         TR(seta,it)tot.insert(*it);
         TR(setb,it)tot.insert(*it);
                  
         int mx=max(ca,cb);
         int s=tot.size();
         if(s==ca && s==cb) printf("A equals B\n");
         else if(s==mx)
         {
              if(s==ca) printf("B is a proper subset of A\n");
              else printf("A is a proper subset of B\n");    
         }
         else if(s==ca+cb) printf("A and B are disjoint\n");
         else printf("I'm confused!\n");
    }
    return 0;
}
